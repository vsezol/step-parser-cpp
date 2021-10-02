#include "ExpressionParser.h"

ExpressionParser::ExpressionParser(string stringExpression, StepReaderConfig readerConfig) :
        stringExpression(stringExpression),
        readerConfig(readerConfig),
        stringUtils(StringUtils()) {}

void ExpressionParser::parse() {
  int nameEndIndex = getExpressionNameEndIndex(stringExpression);
  string expressionName = stringExpression.substr(0, nameEndIndex);
  rootExpression.name = expressionName;

  string expressionCall = stringUtils.removeEnds(stringExpression.substr(nameEndIndex));
  vector<string> arguments = processArguments(expressionCall);

  for (int i = 0; i < arguments.size(); i++) {
    string element = arguments[i];

    if (checkIsExpression(element)) {
      ExpressionParser parser = ExpressionParser(element, readerConfig);
      parser.parse();
      rootExpression.expressions.push_back(parser.getRootExpression());
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
}

Expression ExpressionParser::getRootExpression() {
  return rootExpression;
}

int ExpressionParser::getExpressionNameEndIndex(string expression) {
  int index = -1;
  for (int i = 0; i < expression.length(); i++) {
    if (expression[i] == readerConfig.OPEN_SCOPE_SYMBOL) {
      index = i;
      break;
    }
  }

  return index;
}

bool ExpressionParser::checkIsExpression(string expression) {
  int nameEndIndex = getExpressionNameEndIndex(expression);

  return nameEndIndex > 0;
}

bool ExpressionParser::checkIsLink(string expression) {
  return expression[0] == readerConfig.LINK_BEGIN_SYMBOL;
}

bool ExpressionParser::checkIsArray(string expression) {
  return (expression.find(readerConfig.OPEN_SCOPE_SYMBOL) != string::npos &&
          expression.find(readerConfig.CLOSE_SCOPE_SYMBOL) != string::npos);
}

vector<string> ExpressionParser::processArguments(string content) {
  CutExpressionResult cutExpressionResult = cutExpressions(content);

  content = cutExpressionResult.content;

  vector<string> nonExpressionArguments = stringUtils.split(content,
                                                            string(1, readerConfig.ARGUMENTS_DIVIDER_SYMBOL));

  vector<string> allArguments;

  for (int i = 0; i < cutExpressionResult.expressions.size(); i++) {
    allArguments.push_back(cutExpressionResult.expressions[i]);
  }

  for (int i = 0; i < nonExpressionArguments.size(); i++) {
    allArguments.push_back(nonExpressionArguments[i]);
  }

  return allArguments;
}

CutExpressionResult ExpressionParser::cutExpressions(string content) {
  string newContent = content;
  vector<string> expressions;
  vector<vector<int>> expressionsScopes;

  bool isExpressions = true;
  while (isExpressions) {
    vector<int> expScope = findFullScopeByCallScope(newContent, findCallScopeRange(newContent));

    isExpressions = checkExpressionExistsByScope(expScope);
    if (isExpressions == false) {
      break;
    }

    string exp = newContent.substr(expScope[0], expScope[1] - expScope[0] + 1);
    expressions.push_back(exp);

    int beginIndex = content.find(exp.substr(0, exp.find('(') + 1));
    int endIndex = beginIndex + exp.length() - 1;
    vector<int> normalScope;
    normalScope.push_back(beginIndex);
    normalScope.push_back(endIndex);

    expressionsScopes.push_back(expScope);

    newContent.erase(expScope[0], expScope[1] - expScope[0] + 1);

    newContent = stringUtils.trimByChar(newContent, readerConfig.ARGUMENTS_DIVIDER_SYMBOL);
  }

  CutExpressionResult result = {expressions, expressionsScopes, newContent};

  return result;
}

bool ExpressionParser::checkExpressionExistsByScope(vector<int> scope) {
  return (scope[0] >= 0) && (scope[1] > scope[0]);
}

vector<int> ExpressionParser::findFullScopeByCallScope(string content, vector<int> scope) {
  int beginScopeNameIndex = scope[0];

  for (int i = scope[0] - 1; i >= 0; i--) {
    char element = content[i];

    if (i == 0) {
      beginScopeNameIndex = i;
      break;
    }

    if (element == readerConfig.OPEN_SCOPE_SYMBOL || element == readerConfig.ARGUMENTS_DIVIDER_SYMBOL) {
      beginScopeNameIndex = i + 1;
      break;
    }
  }

  vector<int> fullScope;
  fullScope.push_back(beginScopeNameIndex);
  fullScope.push_back(scope[1]);

  return fullScope;
}

vector<int> ExpressionParser::findCallScopeRange(string content) {
  vector<int> scope;
  scope.push_back(-1);
  scope.push_back(-1);

  for (int i = 0; i < content.length(); i++) {
    char element = content[i];

    if (element == readerConfig.OPEN_SCOPE_SYMBOL) {
      scope[0] = i;
    }

    if (element == readerConfig.CLOSE_SCOPE_SYMBOL) {
      scope[1] = i;
      break;
    }
  }

  return scope;
}