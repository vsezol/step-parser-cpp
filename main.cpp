#include <iostream>

#include <string>

#include "modules/StringUtils.h"
#include "modules/FileReader.h"
#include "modules/StepReaderConfig.h"
#include "modules/SectionStepExtractor.h"

using namespace std;

int main() {
  string filePath = "C:\\vz\\pet\\step-parser\\files\\MBA_N.STP";
  const StepReaderConfig stepReaderConfig = {
          "ENDSEC",
          "HEADER",
          "DATA",
          ";"
  };

  FileReader fileReader = FileReader(filePath);
  string textContent = fileReader.readAsText();

  SectionStepExtractor sectionReader = SectionStepExtractor(stepReaderConfig, textContent);

  string header = sectionReader.extractSectionContent(stepReaderConfig.HEADER_KEYWORD);
  string data = sectionReader.extractSectionContent(stepReaderConfig.DATA_KEYWORD);

  cout << header << endl;

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

