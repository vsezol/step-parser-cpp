#include "FileReader.h"
#include <string>
#include <fstream>

using namespace std;

FileReader::FileReader(string fileName) {
  this->fileName = fileName;
}

string FileReader::readAsText() {
  ifstream inputStream(fileName);

  string text = string((istreambuf_iterator<char>(inputStream)),
                       (istreambuf_iterator<char>()));

  return text;
}