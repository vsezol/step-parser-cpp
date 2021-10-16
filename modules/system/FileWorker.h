#ifndef STEP_PARSER_FILEWORKER_H
#define STEP_PARSER_FILEWORKER_H
#include <string>

using namespace std;

class FileWorker {
public:
  FileWorker(string fileName);

  string read();

  void write(string content);

private:
    string fileName;
};


#endif STEP_PARSER_FILEWORKER_H
