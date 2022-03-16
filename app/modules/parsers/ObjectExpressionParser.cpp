#include "ObjectExpressionParser.h"
#include <iostream>

ObjectExpressionParser::ObjectExpressionParser(
        SimpleExpressionParser * simpleExpressionParser,
        AbstractArgumentsExtractor * argumentsExtractor) :
        simpleExpressionParser(simpleExpressionParser),
        argumentsExtractor(argumentsExtractor) {
}

Expression ObjectExpressionParser::parse(string inputData) {
  Expression rootExpression;
  rootExpression.name = "";

  string stringExpression = inputData;
  stringExpression = StringUtils::removeEnds(stringExpression);

  vector<string> arguments = argumentsExtractor->extract(stringExpression);

  for (int i = 0; i < arguments.size(); i++) {
    rootExpression.expressions.push_back(simpleExpressionParser->parse(arguments[i]));
  }

  return rootExpression;
}