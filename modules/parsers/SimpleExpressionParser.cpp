#include "SimpleExpressionParser.h"
#include <iostream>

SimpleExpressionParser::SimpleExpressionParser(StepReaderConfig readerConfig,
                                               AbstractArgumentsExtractor *argumentsExtractor) :
        ExpressionParser(),
        readerConfig(readerConfig), argumentsExtractor(argumentsExtractor) {
}

Expression SimpleExpressionParser::parse(string inputData) {
  int nameEndIndex = getExpressionNameEndIndex(inputData);

  string expressionName = inputData.substr(0, nameEndIndex);

  Expression rootExpression;
  rootExpression.name = expressionName;
  rootExpression.number = 0;

  string expressionCall = stringUtils.removeEnds(inputData.substr(nameEndIndex));
  vector<string> arguments = argumentsExtractor->extract(expressionCall);

  for (int i = 0; i < arguments.size(); i++) {
    string element = arguments[i];

    if (checkIsExpression(element)) {
      rootExpression.expressions.push_back(parse(element));
    } else if (checkIsLink(element)) {
      rootExpression.links.push_back(element);
    } else if (checkIsArray(element)) {
      rootExpression.arrays.push_back(element);
    } else {
      if (element.size() > 0) {
        rootExpression.values.push_back(element);
      }
    }
  }

  return rootExpression;
}

int SimpleExpressionParser::getExpressionNameEndIndex(string expression) {
  int index = -1;
  for (int i = 0; i < expression.length(); i++) {
    if (expression[i] == readerConfig.OPEN_SCOPE_SYMBOL) {
      index = i;
      break;
    }
  }

  return index;
}

bool SimpleExpressionParser::checkIsExpression(string expression) {
  int nameEndIndex = getExpressionNameEndIndex(expression);

  return nameEndIndex > 0;
}

bool SimpleExpressionParser::checkIsLink(string expression) {
  return expression[0] == readerConfig.LINK_BEGIN_SYMBOL;
}

bool SimpleExpressionParser::checkIsArray(string expression) {
  return (expression.find(readerConfig.OPEN_SCOPE_SYMBOL) != string::npos &&
          expression.find(readerConfig.CLOSE_SCOPE_SYMBOL) != string::npos);
}