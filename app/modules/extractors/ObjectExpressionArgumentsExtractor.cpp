#include "ObjectExpressionArgumentsExtractor.h"

using namespace std;

ObjectExpressionArgumentsExtractor::ObjectExpressionArgumentsExtractor(StepReaderConfig stepReaderConfig) :
        AbstractArgumentsExtractor(stepReaderConfig) {}

vector<string> ObjectExpressionArgumentsExtractor::extract(string content) {
  vector<string> arguments;

  if (content.length() < 0) {
    return arguments;
  }

  string dividerString = StringUtils::charToString(stepReaderConfig.CLOSE_SCOPE_SYMBOL) +
          StringUtils::charToString(stepReaderConfig.EXPRESSION_OBJECT_DIVIDER_SYMBOL);

  arguments = VectorUtils::removeEmptyStrings(StringUtils::split(content, dividerString));

  for (int i = 0; i < arguments.size(); i++) {
    arguments[i] = arguments[i] + StringUtils::charToString(stepReaderConfig.CLOSE_SCOPE_SYMBOL);
    arguments[i] = StringUtils::trimByChar(arguments[i], stepReaderConfig.EXPRESSION_OBJECT_DIVIDER_SYMBOL);
  }

  return arguments;
}