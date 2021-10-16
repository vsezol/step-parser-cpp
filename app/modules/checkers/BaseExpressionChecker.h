#ifndef STEP_PARSER_BASEEXPRESSIONCHECKER_H
#define STEP_PARSER_BASEEXPRESSIONCHECKER_H

#include "AbstractChecker.h"
#include "../structures/StepReaderConfig.h"

class BaseExpressionChecker: public AbstractChecker<string> {
public:
    BaseExpressionChecker(StepReaderConfig stepReaderConfig);

protected:
    StepReaderConfig stepReaderConfig;
};


#endif STEP_PARSER_BASEEXPRESSIONCHECKER_H
