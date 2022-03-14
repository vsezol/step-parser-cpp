#include "EqualityParser.h"
#include <iostream>

EqualityParser::EqualityParser(
        SimpleExpressionParser *simpleExpressionParser,
        ObjectExpressionParser *objectExpressionParser,
        IsObjectExpressionChecker *isObjectExpressionChecker,
        IsSimpleExpressionChecker *isSimpleExpressionChecker,
        EqualityPartsParser *equalityPartsParser
) :
        simpleExpressionParser(simpleExpressionParser),
        objectExpressionParser(objectExpressionParser),
        isObjectExpressionChecker(isObjectExpressionChecker),
        isSimpleExpressionChecker(isSimpleExpressionChecker),
        equalityPartsParser(equalityPartsParser) {}

EqualityParser::~EqualityParser() {
  delete simpleExpressionParser;
  delete objectExpressionParser;
  delete isObjectExpressionChecker;
  delete isSimpleExpressionChecker;
  delete equalityPartsParser;
}

Expression EqualityParser::parse(string equality) {
  vector<string> parts = equalityPartsParser->parse(equality);

  int equalityNumber = stoi(parts[0]);
  string equalityBody = parts[1];

  Expression expression;

  if (isObjectExpressionChecker->check(equalityBody)) {
    expression = objectExpressionParser->parse(equalityBody);
  } else if (isSimpleExpressionChecker->check(equalityBody)) {
    simpleExpressionParser->parse(equalityBody);
    expression = simpleExpressionParser->parse(equalityBody);
  }

  expression.number = equalityNumber;

  return expression;
}