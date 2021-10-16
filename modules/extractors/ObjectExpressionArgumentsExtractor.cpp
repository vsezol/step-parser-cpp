#include "ObjectExpressionArgumentsExtractor.h"

using namespace std;

ObjectExpressionArgumentsExtractor::ObjectExpressionArgumentsExtractor(StepReaderConfig stepReaderConfig): AbstractArgumentsExtractor(stepReaderConfig) {}

vector<string> ObjectExpressionArgumentsExtractor::extract(string content) {
  vector<string> arguments;

  if (content.length() < 0) {
    return arguments;
  }

  string dividerString = stringUtils.charToString(stepReaderConfig.CLOSE_SCOPE_SYMBOL) +
                         stringUtils.charToString(stepReaderConfig.EXPRESSION_OBJECT_DIVIDER_SYMBOL);

  arguments = vectorUtils.removeEmptyStrings(stringUtils.split(content, dividerString));

  for (int i = 0; i < arguments.size(); i++) {
    arguments[i] = arguments[i] + stringUtils.charToString(stepReaderConfig.CLOSE_SCOPE_SYMBOL);
    arguments[i] = stringUtils.trimByChar(arguments[i], stepReaderConfig.EXPRESSION_OBJECT_DIVIDER_SYMBOL);
  }

  return arguments;
}