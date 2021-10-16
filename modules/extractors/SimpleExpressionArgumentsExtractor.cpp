#include "SimpleExpressionArgumentsExtractor.h"

using namespace std;

SimpleExpressionArgumentsExtractor::SimpleExpressionArgumentsExtractor(StepReaderConfig stepReaderConfig)
        : AbstractArgumentsExtractor(stepReaderConfig) {}

vector<string> SimpleExpressionArgumentsExtractor::extract(string content) {
  CutExpressionResult cutExpressionResult = cutExpressions(content);

  content = cutExpressionResult.content;

  vector<string> nonExpressionArguments =
          stringUtils.split(content,
                            stringUtils.charToString(
                                    stepReaderConfig.ARGUMENTS_DIVIDER_SYMBOL
                            )
          );

  vector<string> allArguments;

  for (int i = 0; i < cutExpressionResult.expressions.size(); i++) {
    allArguments.push_back(cutExpressionResult.expressions[i]);
  }

  for (int i = 0; i < nonExpressionArguments.size(); i++) {
    allArguments.push_back(nonExpressionArguments[i]);
  }

  for (int i = 0; i < allArguments.size(); i++) {
    allArguments[i] = stringUtils.trimByChar(allArguments[i], stepReaderConfig.EXPRESSION_OBJECT_DIVIDER_SYMBOL);
  }

  return allArguments;
}

CutExpressionResult SimpleExpressionArgumentsExtractor::cutExpressions(string content) {
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

    int beginIndex = content.find(exp.substr(0, exp.find(stepReaderConfig.OPEN_SCOPE_SYMBOL) + 1));
    int endIndex = beginIndex + exp.length() - 1;
    vector<int> normalScope;
    normalScope.push_back(beginIndex);
    normalScope.push_back(endIndex);

    expressionsScopes.push_back(expScope);

    newContent.erase(expScope[0], expScope[1] - expScope[0] + 1);

    newContent = stringUtils.trimByChar(newContent, stepReaderConfig.ARGUMENTS_DIVIDER_SYMBOL);
  }

  CutExpressionResult result = {expressions, expressionsScopes, newContent};

  return result;
}

bool SimpleExpressionArgumentsExtractor::checkExpressionExistsByScope(vector<int> scope) {
  return (scope[0] >= 0) && (scope[1] > scope[0]);
}


vector<int> SimpleExpressionArgumentsExtractor::findFullScopeByCallScope(string content, vector<int> scope) {
  int beginScopeNameIndex = scope[0];

  for (int i = scope[0] - 1; i >= 0; i--) {
    char element = content[i];

    if (i == 0) {
      beginScopeNameIndex = i;
      break;
    }

    if (element == stepReaderConfig.OPEN_SCOPE_SYMBOL || element == stepReaderConfig.ARGUMENTS_DIVIDER_SYMBOL) {
      beginScopeNameIndex = i + 1;
      break;
    }
  }

  vector<int> fullScope;
  fullScope.push_back(beginScopeNameIndex);
  fullScope.push_back(scope[1]);

  return fullScope;
}

vector<int> SimpleExpressionArgumentsExtractor::findCallScopeRange(string content) {
  vector<int> scope;
  scope.push_back(-1);
  scope.push_back(-1);

  for (int i = 0; i < content.length(); i++) {
    char element = content[i];

    if (element == stepReaderConfig.OPEN_SCOPE_SYMBOL) {
      scope[0] = i;
    }

    if (element == stepReaderConfig.CLOSE_SCOPE_SYMBOL) {
      scope[1] = i;
      break;
    }
  }

  return scope;
}