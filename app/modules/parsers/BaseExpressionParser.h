#ifndef STEP_PARSER_BASEEXPRESSIONPARSER_H
#define STEP_PARSER_BASEEXPRESSIONPARSER_H

#include <string>
#include <vector>

#include "../structures/StepReaderConfig.h"
#include "../structures/Expression.h"
#include "../utils/StringUtils.h"
#include "AbstractParser.h"

class BaseExpressionParser: public AbstractParser<string, Expression>{
public:
    BaseExpressionParser();

    virtual Expression parse(string inputData) = 0;

protected:
    StringUtils stringUtils;
};


#endif STEP_PARSER_BASEEXPRESSIONPARSER_H
