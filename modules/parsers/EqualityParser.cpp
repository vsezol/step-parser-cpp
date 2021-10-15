#include "EqualityParser.h"

EqualityParser::EqualityParser(StepReaderConfig readerConfig): readerConfig(readerConfig) {
  stringUtils = StringUtils();
}

vector<string> EqualityParser::parse(string inputData) {
  vector<string> equality;

  equality.push_back(extractNumber(inputData));
  equality.push_back(extractExpression(inputData));

  return equality;
}

string EqualityParser::extractNumber(string inputData) {
  vector<string> parts = stringUtils.split(inputData, stringUtils.charToString(readerConfig.EQUALITY_SYMBOL));
  string stringNumber = stringUtils.split(parts[0], stringUtils.charToString(readerConfig.LINK_BEGIN_SYMBOL))[1];

  return stringNumber;
}

string EqualityParser::extractExpression(string inputData) {
  vector<string> parts = stringUtils.split(inputData, stringUtils.charToString(readerConfig.EQUALITY_SYMBOL));
  string stringExpression = parts[1];

  return stringExpression;
}