#include <string>
#include <iostream>
#include <unordered_map>

#include "modules/system/FileWorker.h"
#include "modules/utils/StringUtils.h"
#include "modules/structures/StepReaderConfig.h"
#include "modules/structures/ExecutionConfig.h"
#include "modules/parsers/SimpleExpressionParser.h"
#include "modules/parsers/ObjectExpressionParser.h"
#include "modules/parsers/EqualityPartsParser.h"
#include "modules/parsers/EqualityParser.h"
#include "modules/checkers/IsSimpleExpressionChecker.h"
#include "modules/checkers/IsObjectExpressionChecker.h"
#include "modules/converters/ExpressionToJsonConverter.h"
#include "modules/converters/ExpressionByNumberToJsonConverter.h"
#include "modules/converters/TreeExpressionToJsonConverter.h"
#include "modules/extractors/SectionStepExtractor.h"
#include "modules/extractors/EqualitiesExtractor.h"
#include "modules/extractors/SimpleExpressionArgumentsExtractor.h"
#include "modules/extractors/ObjectExpressionArgumentsExtractor.h"
#include "configs/stepReaderConfig.cpp"
#include "modules/structures/TreeExpression.h"
#include "modules/structures/Expression.h"
#include "modules/builders/TreeExpressionBuilder.h"
#include "modules/calculators/TreeExpressionHeightCalculator.h"
#include "modules/loggers/ProgressLogger.h"

#include "modules/functions/getUnorderedMapValues.cpp"

using namespace std;

vector<string> getExecutionArguments(int argumentsCount, char **arguments) {
  vector<string> executionArguments;
  for (int i = 0; i < argumentsCount; i++) {
    executionArguments.push_back(string(arguments[i]));
  }
  return executionArguments;
}

int main(int argumentsCount, char **arguments) {
  const int STAGES_COUNT = 7;
  string STAGES[STAGES_COUNT] = {
          "reading file",
          "extracting equalities",
          "parsing expressions",
          "building expressions tree",
          "filtration expressions tree",
          "writing to file",
          "finishing"
  };

  ProgressLogger progressPrinter = ProgressLogger(STAGES, STAGES_COUNT);

  // configuration
  ExecutionConfig *executionConfig = new ExecutionConfig({
                                                                 "",
                                                                 "",
                                                                 false,
                                                                 false,
                                                                 ""
                                                         });
  vector<string> executionArguments = getExecutionArguments(argumentsCount, arguments);
  executionConfig->updateByArguments(executionArguments);

  // reading
  progressPrinter.logCurrentStage();
  string textContent = FileWorker(executionConfig->inputPath).read();

  SectionStepExtractor sectionReader = SectionStepExtractor(stepReaderConfig, textContent);
  string header = sectionReader.extractSectionContent(stepReaderConfig.HEADER_KEYWORD);
  string data = sectionReader.extractSectionContent(stepReaderConfig.DATA_KEYWORD);

  // extracting
  progressPrinter.toNextStage();
  progressPrinter.logCurrentStage();
  EqualitiesExtractor equalitiesExtractor = EqualitiesExtractor(stepReaderConfig);
  vector<string> equalities = equalitiesExtractor.extract(data);

  EqualityParser equalityParser = EqualityParser(
          new SimpleExpressionParser(
                  stepReaderConfig,
                  new SimpleExpressionArgumentsExtractor(stepReaderConfig)
          ),
          new ObjectExpressionParser(
                  new SimpleExpressionParser(
                          stepReaderConfig,
                          new SimpleExpressionArgumentsExtractor(stepReaderConfig)
                  ),
                  new ObjectExpressionArgumentsExtractor(stepReaderConfig)
          ),
          new IsObjectExpressionChecker(stepReaderConfig),
          new IsSimpleExpressionChecker(stepReaderConfig),
          new EqualityPartsParser(stepReaderConfig)
  );

  // parsing
  progressPrinter.toNextStage();
  progressPrinter.logCurrentStage();
  unordered_map<short, Expression> expressionByNumber;
  expressionByNumber.reserve(equalities.size());
  for (int i = 0; i < equalities.size(); i++) {
    Expression expression = equalityParser.parse(equalities[i]);
    expressionByNumber.emplace(expression.number, expression);
  }

  // building tree
  progressPrinter.toNextStage();
  progressPrinter.logCurrentStage();
  TreeExpressionBuilder treeExpressionBuilder = TreeExpressionBuilder(stepReaderConfig, expressionByNumber);

  unordered_map<short, TreeExpression> treeExpressionByNumber;
  treeExpressionByNumber.reserve(equalities.size());

  for (auto tableItem = expressionByNumber.begin(); tableItem != expressionByNumber.end(); tableItem++) {
    treeExpressionByNumber.emplace(
            tableItem->first,
            treeExpressionBuilder.build(tableItem->second)
    );
  }

  // filtering
  progressPrinter.toNextStage();
  progressPrinter.logCurrentStage();
  unordered_map<short, TreeExpression> filteredTreeExpressionByNumber;
  for (auto tableItem = treeExpressionByNumber.begin();
       tableItem != treeExpressionByNumber.end(); tableItem++) {
    TreeExpression item = tableItem->second;

    if (
            executionConfig->filterBy.empty() ||
            StringUtils::hasSubstring(item.name, executionConfig->filterBy) ||
            StringUtils::hasSubstring(to_string(item.number), executionConfig->filterBy)
    ) {
      filteredTreeExpressionByNumber.emplace(tableItem->first, tableItem->second);
    }
  }

  // writing
  TreeExpression rootTreeExpression;
  rootTreeExpression.children = getUnorderedMapValues(filteredTreeExpressionByNumber);
  rootTreeExpression.name = "ROOT";
  rootTreeExpression.number = 0;

  progressPrinter.toNextStage();
  progressPrinter.logCurrentStage();
  string serializedRootTreeExpression = TreeExpressionToJsonConverter(*executionConfig, stepReaderConfig).convert(
          rootTreeExpression);
  FileWorker(executionConfig->outputPath).write(serializedRootTreeExpression);

  // finishing
  progressPrinter.toNextStage();
  progressPrinter.logCurrentStage();
  delete executionConfig;

  return 0;
}