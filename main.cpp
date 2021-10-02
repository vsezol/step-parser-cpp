#include <iostream>

#include <string>

#include "modules/utils/StringUtils.h"
#include "modules/readers/FileReader.h"
#include "modules/structures/StepReaderConfig.h"
#include "modules/extractors/SectionStepExtractor.h"
#include "modules/structures/Expression.h"
#include "modules/parsers/ExpressionParser.h"

using namespace std;

//string EXAMPLE_EXPRESSION = "PLANE_ANGLE_MEASURE_WITH_UNIT(PLANE_ANGLE_MEASURE(0.0174532925, PLANE_ANGLE_MEASURE('JOPA')),#30,$,*,0.,6,'Maximum Tolerance applied to model',SI_UNIT(.MILLI.,.METRE.))";
string EXAMPLE_EXPRESSION = "CC_DESIGN_PERSON_AND_ORGANIZATION_ASSIGNMENT(#4605,#4606,(#4600),(''),(#4572,#4570))";

int main() {
  string filePath = "C:\\vz\\pet\\step-parser\\files\\MBA_N.STP";
  const StepReaderConfig stepReaderConfig = {
          "ENDSEC",
          "HEADER",
          "DATA",
          ";",
          '(',
          ')',
          ',',
          '#',
          '\n'
  };

  FileReader fileReader = FileReader(filePath);
  string textContent = fileReader.readAsText();

  SectionStepExtractor sectionReader = SectionStepExtractor(stepReaderConfig, textContent);

  string header = sectionReader.extractSectionContent(stepReaderConfig.HEADER_KEYWORD);
  string data = sectionReader.extractSectionContent(stepReaderConfig.DATA_KEYWORD);

  ExpressionParser expressionParser = ExpressionParser(EXAMPLE_EXPRESSION, stepReaderConfig);
  expressionParser.parse();

  Expression expression = expressionParser.getRootExpression();



//  ExpressionPrinter(4).print(expressionParser.getRootExpression());

//  for (int i = 0; i < array.size(); i++) {
//    vector<string> rootExpression = stringUtils.split(array[i], "#");
//
//    rootExpression = removeEmptyStrings(rootExpression);
//    printArrayOfStrings(rootExpression);
//
//    //    rootExpression.erase(rootExpression.begin());
//    //    rootExpression = stringUtils.split(rootExpression[1], "=");
//  }

  cout << "End of program" << endl;

  return 0;
}

