#include "StringUtils.h"

vector<string> StringUtils::split(string str, string delimiter) {
  size_t startPos = 0;
  size_t endPos, delimiterLength = delimiter.length();

  string token;
  vector<string> result;

  while ((endPos = str.find(delimiter, startPos)) != string::npos) {
    token = str.substr(startPos, endPos - startPos);
    startPos = endPos + delimiterLength;
    result.push_back(token);
  }

  result.push_back(str.substr(startPos));

  return result;
}