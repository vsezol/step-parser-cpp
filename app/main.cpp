#include <string>

#include "modules/system/FileWorker.h"
#include "modules/utils/StringUtils.h"
#include "modules/structures/StepReaderConfig.h"
#include "modules/structures/Expression.h"
#include "modules/parsers/SimpleExpressionParser.h"
#include "modules/parsers/ObjectExpressionParser.h"
#include "modules/parsers/EqualityPartsParser.h"
#include "modules/parsers/EqualityParser.h"
#include "modules/checkers/IsSimpleExpressionChecker.h"
#include "modules/checkers/IsObjectExpressionChecker.h"
#include "modules/converters/ExpressionToJsonConverter.h"
#include "modules/extractors/SectionStepExtractor.h"
#include "modules/extractors/EqualitiesExtractor.h"
#include "modules/extractors/SimpleExpressionArgumentsExtractor.h"
#include "modules/extractors/ObjectExpressionArgumentsExtractor.h"
#include "configs/stepReaderConfig.cpp"

using namespace std;

int main() {
  string inputFilePath = "C:\\vz\\pet\\step-parser\\files\\MBA_N.STP";
  string outputFilePath = "C:\\vz\\pet\\step-parser\\files\\output\\output.json";

  string textContent = FileWorker(inputFilePath).read();

  SectionStepExtractor sectionReader = SectionStepExtractor(stepReaderConfig, textContent);
  string header = sectionReader.extractSectionContent(stepReaderConfig.HEADER_KEYWORD);
  string data = sectionReader.extractSectionContent(stepReaderConfig.DATA_KEYWORD);

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

  Expression mainExpression;
  mainExpression.name = "MAIN_EXPRESSION";
  for (int i = 0; i < equalities.size(); i++) {
    Expression expression = equalityParser.parse(equalities[i]);
    mainExpression.expressions.push_back(expression);
  }

  string serializedExpression = ExpressionToJsonConverter().convert(mainExpression);

  FileWorker(outputFilePath).write(serializedExpression);

  return 0;
}