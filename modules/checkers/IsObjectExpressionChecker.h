#ifndef STEP_PARSER_ISOBJECTEXPRESSIONCHECKER_H
#define STEP_PARSER_ISOBJECTEXPRESSIONCHECKER_H

#include <string>
#include "ExpressionChecker.h"
#include "../structures/StepReaderConfig.h"


class IsObjectExpressionChecker : public ExpressionChecker {
public:
    IsObjectExpressionChecker(StepReaderConfig stepReaderConfig);

    bool check(string content) override;
};


#endif STEP_PARSER_ISOBJECTEXPRESSIONCHECKER_H
