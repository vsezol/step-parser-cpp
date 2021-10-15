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

string StringUtils::removeEnds(string str) {
  str = removeFirstElement(str);
  str = removeLastElement(str);
  return str;
}

string StringUtils::removeLastElement(string str) {
  str.erase(str.length() - 1);
  return str;
}


string StringUtils::removeFirstElement(string str) {
  str.erase(0, 1);
  return str;
}

string StringUtils::trimByChar(string str, char chr) {
  if (str.length() <= 0) {
    return str;
  }

  if (str[0] == chr) {
    str = removeFirstElement(str);
  }

  if (str[str.length() - 1] == chr) {
    str = removeLastElement(str);
  }

  return str;
}

string StringUtils::charToString(char chr) {
  string newString = "";
  newString += chr;

  return newString;
}