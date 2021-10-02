#ifndef STEP_PARSER_FILEREADER_H
#define STEP_PARSER_FILEREADER_H
#include <string>

using namespace std;

class FileReader {
public:
  FileReader(string fileName);
  string readAsText();

private:
    string fileName;
};


#endif STEP_PARSER_FILEREADER_H
