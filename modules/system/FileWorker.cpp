#include "FileWorker.h"
#include <string>
#include <fstream>

using namespace std;

FileWorker::FileWorker(string fileName): fileName(fileName) {}

string FileWorker::read() {
  ifstream inputStream(fileName);

  string text = string((istreambuf_iterator<char>(inputStream)),
                       (istreambuf_iterator<char>()));

  return text;
}

void FileWorker::write(string content) {
  ofstream outputStream(fileName);

  if (outputStream.is_open()) {
    outputStream << content;
    outputStream.close();
  }
}