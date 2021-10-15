#include "IsSimpleExpressionChecker.h"

IsSimpleExpressionChecker::IsSimpleExpressionChecker(StepReaderConfig stepReaderConfig)
        : ExpressionChecker(stepReaderConfig) {}

bool IsSimpleExpressionChecker::check(string content) {
  return false;
}