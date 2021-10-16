#include "IsSimpleExpressionChecker.h"

IsSimpleExpressionChecker::IsSimpleExpressionChecker(StepReaderConfig stepReaderConfig)
        : BaseExpressionChecker(stepReaderConfig) {}

bool IsSimpleExpressionChecker::check(string content) {
  return (content[0] != stepReaderConfig.OPEN_SCOPE_SYMBOL &&
          content[content.length() - 1] == stepReaderConfig.CLOSE_SCOPE_SYMBOL);
}