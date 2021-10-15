#ifndef STEP_PARSER_ISSIMPLEEXPRESSIONCHECKER_H
#define STEP_PARSER_ISSIMPLEEXPRESSIONCHECKER_H

#include <string>
#include "ExpressionChecker.h"
#include "../structures/StepReaderConfig.h"

using namespace std;

class IsSimpleExpressionChecker : public ExpressionChecker {
public:
    IsSimpleExpressionChecker(StepReaderConfig stepReaderConfig);

    bool check(string content) override;
};


#endif STEP_PARSER_ISSIMPLEEXPRESSIONCHECKER_H
