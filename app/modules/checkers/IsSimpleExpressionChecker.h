#ifndef STEP_PARSER_ISSIMPLEEXPRESSIONCHECKER_H
#define STEP_PARSER_ISSIMPLEEXPRESSIONCHECKER_H

#include <string>
#include "BaseExpressionChecker.h"
#include "../structures/StepReaderConfig.h"

using namespace std;

class IsSimpleExpressionChecker : public BaseExpressionChecker {
public:
    IsSimpleExpressionChecker(StepReaderConfig stepReaderConfig);

    bool check(string content) override;
};


#endif STEP_PARSER_ISSIMPLEEXPRESSIONCHECKER_H
