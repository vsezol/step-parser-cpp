#include "FileReader.h"
#include <string>
#include <fstream>

using namespace std;

FileReader::FileReader(string fileName) {
  this->fileName = fileName;
}

string FileReader::readAsText() {
  string text;

  ifstream inputStream(this->fileName);
  if (inputStream.is_open()) {
    string line;
    while (getline(inputStream, line)) {
      text += line;
    }
  }
  inputStream.close();

  return text;
}