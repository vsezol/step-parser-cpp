#include <iostream>

#include <string>
#include <vector>

#include "StringUtils.h"
#include "FileReader.h"
#include "VectorUtils.h"

using namespace std;

const struct StepReaderConfig {
    string END_SECTION_KEYWORD;
    string HEADER_KEYWORD;
    string DATA_KEYWORD;
    string STRING_DIVIDER;
};

class StepReader {
public:
    StepReader(StepReaderConfig config, string content): config(config) {
      sections = stringUtils.split(content, config.END_SECTION_KEYWORD);
    };

    string getSectionContent(string keyword) {
      string section = getSectionByKeyword(keyword);

      return stringUtils.split(section, wrapKeyword(keyword))[1];
    }

private:
    vector<string> sections;
    StepReaderConfig config;

    StringUtils stringUtils = StringUtils();

    string getSectionByKeyword(string keyword) {
      return sections[getSectionIndexByKeyword(keyword)];
    }

    int getSectionIndexByKeyword(string keyword) {
      for (int i = 0; i < sections.size(); i++) {
        string section = sections[i];

        if (section.find(keyword) != string::npos) {
          return i;
        }
      }
    }

    string wrapKeyword(string keyword) {
      return keyword + config.STRING_DIVIDER;
    }
};

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

  StepReader stepReader = StepReader(stepReaderConfig, textContent);

  string header = stepReader.getSectionContent(stepReaderConfig.HEADER_KEYWORD);
  string data = stepReader.getSectionContent(stepReaderConfig.DATA_KEYWORD);

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

