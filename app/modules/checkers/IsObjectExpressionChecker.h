#ifndef STEP_PARSER_ISOBJECTEXPRESSIONCHECKER_H
#define STEP_PARSER_ISOBJECTEXPRESSIONCHECKER_H

#include <string>
#include "BaseExpressionChecker.h"
#include "../structures/StepReaderConfig.h"

class IsObjectExpressionChecker : public BaseExpressionChecker {
public:
    IsObjectExpressionChecker(StepReaderConfig stepReaderConfig);

    bool check(string content) override;
};


#endif STEP_PARSER_ISOBJECTEXPRESSIONCHECKER_H
