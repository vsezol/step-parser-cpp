#include <string>

#include "modules/utils/StringUtils.h"
#include "modules/system/FileWorker.h"
#include "modules/structures/StepReaderConfig.h"
#include "modules/extractors/SectionStepExtractor.h"
#include "modules/extractors/ObjectExpressionArgumentsExtractor.h"
#include "modules/structures/Expression.h"
#include "modules/parsers/SimpleExpressionParser.h"
#include "modules/parsers/ObjectExpressionParser.h"
#include "modules/parsers/EqualityParser.h"
#include "modules/checkers/IsSimpleExpressionChecker.h"
#include "modules/checkers/IsObjectExpressionChecker.h"
#include "modules/converters/ExpressionToJsonConverter.h"
#include "modules/extractors/SimpleExpressionArgumentsExtractor.h"

using namespace std;

vector<string> getEqualities(string data, char STRING_DIVIDER) {
  StringUtils stringUtils = StringUtils();
  vector<string> equalities = stringUtils.split(data, stringUtils.charToString(STRING_DIVIDER));
  equalities.pop_back();

  return equalities;
}

int main() {
  string filePath = "C:\\vz\\pet\\step-parser\\files\\MBA_N.STP";
  const StepReaderConfig stepReaderConfig = {
          "ENDSEC",
          "HEADER",
          "DATA",
          ';',
          '(',
          ')',
          ',',
          '#',
          '=',
          '\n'
  };

  string textContent = FileWorker(filePath).read();

  SectionStepExtractor sectionReader = SectionStepExtractor(stepReaderConfig, textContent);

  string header = sectionReader.extractSectionContent(stepReaderConfig.HEADER_KEYWORD);
  string data = sectionReader.extractSectionContent(stepReaderConfig.DATA_KEYWORD);

  vector<string> equalities = getEqualities(data, stepReaderConfig.STRING_DIVIDER);

  IsObjectExpressionChecker isObjectExpressionChecker = IsObjectExpressionChecker(stepReaderConfig);
  IsSimpleExpressionChecker isSimpleExpressionChecker = IsSimpleExpressionChecker(stepReaderConfig);

  Expression mainExpression;
  mainExpression.name = "MAIN_EXPRESSION";

  for (int i = 0; i < equalities.size(); i++) {
    string equality = equalities[i];

    EqualityParser equalityParser = EqualityParser(stepReaderConfig);
    vector<string> parts = equalityParser.parse(equality);

    int equalityNumber = stoi(parts[0]);
    string equalityBody = parts[1];

    Expression expression;

    if (isObjectExpressionChecker.check(equalityBody)) {
      ObjectExpressionParser objectExpressionParser = ObjectExpressionParser(
              new SimpleExpressionParser(stepReaderConfig,
                                         new SimpleExpressionArgumentsExtractor(
                                                 stepReaderConfig)),
              new ObjectExpressionArgumentsExtractor(stepReaderConfig)
      );
      expression = objectExpressionParser.parse(equalityBody);
    } else {
      SimpleExpressionParser simpleExpressionParser = SimpleExpressionParser(
              stepReaderConfig,
              new SimpleExpressionArgumentsExtractor(
                      stepReaderConfig)
      );
      simpleExpressionParser.parse(equalityBody);
      expression = simpleExpressionParser.parse(equalityBody);
    }

    expression.number = equalityNumber;

    mainExpression.expressions.push_back(expression);
  }

  string serializedExpression = ExpressionToJsonConverter().convert(mainExpression);

  string outputPath = "C:\\vz\\pet\\step-parser\\files\\output\\output.json";
  FileWorker(outputPath).write(serializedExpression);

  return 0;
}