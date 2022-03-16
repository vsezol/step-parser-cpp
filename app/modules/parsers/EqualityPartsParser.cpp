#include "EqualityPartsParser.h"

EqualityPartsParser::EqualityPartsParser(StepReaderConfig readerConfig): readerConfig(readerConfig) {}

vector<string> EqualityPartsParser::parse(string inputData) {
  vector<string> equality;

  equality.push_back(extractNumber(inputData));
  equality.push_back(extractExpression(inputData));

  return equality;
}

string EqualityPartsParser::extractNumber(string inputData) {
  vector<string> parts = StringUtils::split(inputData, StringUtils::charToString(readerConfig.EQUALITY_SYMBOL));
  string stringNumber = StringUtils::split(parts[0], StringUtils::charToString(readerConfig.LINK_BEGIN_SYMBOL))[1];

  return stringNumber;
}

string EqualityPartsParser::extractExpression(string inputData) {
  vector<string> parts = StringUtils::split(inputData, StringUtils::charToString(readerConfig.EQUALITY_SYMBOL));
  string stringExpression = parts[1];

  return stringExpression;
}