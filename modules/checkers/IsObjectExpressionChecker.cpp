#include "IsObjectExpressionChecker.h"

IsObjectExpressionChecker::IsObjectExpressionChecker(StepReaderConfig stepReaderConfig) :
        ExpressionChecker(stepReaderConfig) {}

bool IsObjectExpressionChecker::check(string content) {
  return true;
}