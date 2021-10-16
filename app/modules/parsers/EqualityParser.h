#ifndef STEP_PARSER_EQUALITYPARSER_H
#define STEP_PARSER_EQUALITYPARSER_H

#include <vector>

#include "AbstractParser.h"
#include "../structures/Expression.h"
#include "../utils/StringUtils.h"
#include "EqualityPartsParser.h"
#include "../parsers/SimpleExpressionParser.h"
#include "../parsers/ObjectExpressionParser.h"
#include "../checkers/IsObjectExpressionChecker.h"
#include "../checkers/IsSimpleExpressionChecker.h"

class EqualityParser : public AbstractParser<string, Expression> {
public:
    EqualityParser(
            SimpleExpressionParser *simpleExpressionParser,
            ObjectExpressionParser *objectExpressionParser,
            IsObjectExpressionChecker *isObjectExpressionChecker,
            IsSimpleExpressionChecker *isSimpleExpressionChecker,
            EqualityPartsParser *equalityPartsParser
    );

    ~EqualityParser();

    Expression parse(string inputData) override;

private:
    SimpleExpressionParser *simpleExpressionParser;
    ObjectExpressionParser *objectExpressionParser;
    IsObjectExpressionChecker *isObjectExpressionChecker;
    IsSimpleExpressionChecker *isSimpleExpressionChecker;
    EqualityPartsParser *equalityPartsParser;
};


#endif STEP_PARSER_EQUALITYPARSER_H
