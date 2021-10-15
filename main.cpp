#include <iostream>

#include <string>

#include "modules/utils/StringUtils.h"
#include "modules/readers/FileReader.h"
#include "modules/structures/StepReaderConfig.h"
#include "modules/extractors/SectionStepExtractor.h"
#include "modules/extractors/ObjectArgumentsExtractor.h"
#include "modules/structures/Expression.h"
#include "modules/parsers/SimpleExpressionParser.h"
#include "modules/parsers/ObjectExpressionParser.h"
#include "modules/parsers/EqualityParser.h"
#include "modules/checkers/IsSimpleExpressionChecker.h"
#include "modules/checkers/IsObjectExpressionChecker.h"
#include "modules/converters/ExpressionToVzConverter.h"

using namespace std;

string EXAMPLE_EQUALITY = "(\n"
                          "BOUNDED_SURFACE()\n"
                          "B_SPLINE_SURFACE(2,1,((#969,#970),(#971,#972),(#973,#974)),.UNSPECIFIED.,\n"
                          ".F.,.F.,.F.)\n"
                          "B_SPLINE_SURFACE_WITH_KNOTS((3,3),(2,2),(0.,1.),(0.,1.),.UNSPECIFIED.)\n"
                          "GEOMETRIC_REPRESENTATION_ITEM()\n"
                          "RATIONAL_B_SPLINE_SURFACE(((0.400039406982928,0.400039406982928),(0.599960593017072,\n"
                          "0.599960593017072),(0.400039406982928,0.400039406982928)))\n"
                          "REPRESENTATION_ITEM('')\n"
                          "SURFACE()\n"
                          ")";


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

  FileReader fileReader = FileReader(filePath);
  string textContent = fileReader.readAsText();

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
    expression.number = equalityNumber;

    if (isObjectExpressionChecker.check(equalityBody)) {
      ObjectExpressionParser objectExpressionParser = ObjectExpressionParser(
              new SimpleExpressionParser(stepReaderConfig),
              new ObjectArgumentsExtractor(stepReaderConfig)
      );
      expression = objectExpressionParser.parse(equalityBody);
    } else if (isSimpleExpressionChecker.check(equalityBody)) {
      SimpleExpressionParser simpleExpressionParser = SimpleExpressionParser(stepReaderConfig);
      simpleExpressionParser.parse(equalityBody);
      expression = simpleExpressionParser.parse(equalityBody);
    }

    mainExpression.expressions.push_back(expression);
  }

  cout << ExpressionToVzConverter(mainExpression, vzConfig).convert() << endl;

  cout << "End of program" << endl;

  return 0;
}