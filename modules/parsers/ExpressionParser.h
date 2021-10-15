#ifndef STEP_PARSER_EXPRESSIONPARSER_H
#define STEP_PARSER_EXPRESSIONPARSER_H

#include <string>
#include <vector>

#include "../structures/StepReaderConfig.h"
#include "../structures/Expression.h"
#include "../utils/StringUtils.h"
#include "AbstractParser.h"

class ExpressionParser: public AbstractParser<string, Expression>{
public:
    ExpressionParser();

    virtual Expression parse(string inputData) = 0;

protected:
    StringUtils stringUtils;
};


#endif STEP_PARSER_EXPRESSIONPARSER_H
