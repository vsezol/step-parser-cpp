#ifndef STEP_PARSER_EXPRESSIONCHECKER_H
#define STEP_PARSER_EXPRESSIONCHECKER_H

#include <string>
#include "AbstractChecker.h"
#include "../structures/StepReaderConfig.h"

class ExpressionChecker: public AbstractChecker<string> {
public:
    ExpressionChecker(StepReaderConfig stepReaderConfig);

protected:
    StepReaderConfig stepReaderConfig;
};


#endif STEP_PARSER_EXPRESSIONCHECKER_H
