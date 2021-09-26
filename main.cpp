#include <iostream>

#include <string>

#include "modules/StringUtils.h"
#include "modules/FileReader.h"
#include "modules/StepReaderConfig.h"
#include "modules/SectionStepExtractor.h"
#include "modules/Expression.h"
#include "modules/ExpressionParser.h"

using namespace std;

string EXAMPLE_EXPRESSION = "PLANE_ANGLE_MEASURE_WITH_UNIT(PLANE_ANGLE_MEASURE(0.0174532925),#30,$,*,0.,6,'Maximum Tolerance applied to model',SI_UNIT(.MILLI.,.METRE.))";

class ExpressionPrinter {
public:
    ExpressionPrinter(int tabSize): tabSize(tabSize) {}

    void print(Expression exp, int tab = 0) {
      string tabs = "";
      for (int i = 0; i < tab; i++) {
        tabs += " ";
      }

      if (tab != 0) {
        cout << "  " << exp.name << ":" << endl;
      } else {
        cout << exp.name << endl;
      }

      if (exp.links.size() > 0) {
        cout << tabs << "  " << "links:" << endl;
        printPrimitives(exp.links, tabs);
      }

      if (exp.values.size() > 0) {
        cout << tabs << "  " << "values:" << endl;
        printPrimitives(exp.values, tabs);
      }

      if (exp.expressions.size() > 0) {
        tab = tab + tabSize;
        for (int i = 0; i < exp.expressions.size(); i++) {
          print(exp.expressions[i], tab);
        }
      }
    }

private:
    int tabSize;

    void printPrimitives(vector<string> items, string tabs) {
      for (int i = 0; i < items.size(); i++) {
        cout << tabs << "    - " << items[i] << endl;
      }
    }
};

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
          '#'
  };

  FileReader fileReader = FileReader(filePath);
  string textContent = fileReader.readAsText();

  SectionStepExtractor sectionReader = SectionStepExtractor(stepReaderConfig, textContent);

  string header = sectionReader.extractSectionContent(stepReaderConfig.HEADER_KEYWORD);
  string data = sectionReader.extractSectionContent(stepReaderConfig.DATA_KEYWORD);

  ExpressionParser expressionParser = ExpressionParser(EXAMPLE_EXPRESSION, stepReaderConfig);
  expressionParser.parse();

  ExpressionPrinter(4).print(expressionParser.getExpression());

//  for (int i = 0; i < array.size(); i++) {
//    vector<string> expression = stringUtils.split(array[i], "#");
//
//    expression = removeEmptyStrings(expression);
//    printArrayOfStrings(expression);
//
//    //    expression.erase(expression.begin());
//    //    expression = stringUtils.split(expression[1], "=");
//  }

  cout << "End of program" << endl;

  return 0;
}

