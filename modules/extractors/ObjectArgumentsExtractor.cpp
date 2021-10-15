#include "ObjectArgumentsExtractor.h"
#include <iostream>

using namespace std;

ObjectArgumentsExtractor::ObjectArgumentsExtractor(StepReaderConfig stepReaderConfig): AbstractArgumentsExtractor(stepReaderConfig) {}

vector<string> ObjectArgumentsExtractor::extract(string content) {
  vector<string> arguments;

  if (content.length() < 0) {
    return arguments;
  }

  string dividerString = stringUtils.charToString(stepReaderConfig.CLOSE_SCOPE_SYMBOL) +
                         stringUtils.charToString(stepReaderConfig.EXPRESSION_OBJECT_DIVIDER_SYMBOL);

  arguments = vectorUtils.removeEmptyStrings(stringUtils.split(content, dividerString));

  for (int i = 0; i < arguments.size(); i++) {
    arguments[i] = arguments[i] + stringUtils.charToString(stepReaderConfig.CLOSE_SCOPE_SYMBOL);
  }

  return arguments;
}