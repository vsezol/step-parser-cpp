#include "IsObjectExpressionChecker.h"

IsObjectExpressionChecker::IsObjectExpressionChecker(StepReaderConfig stepReaderConfig) :
        ExpressionChecker(stepReaderConfig) {}

bool IsObjectExpressionChecker::check(string content) {
  return content[0] == stepReaderConfig.OPEN_SCOPE_SYMBOL;
}