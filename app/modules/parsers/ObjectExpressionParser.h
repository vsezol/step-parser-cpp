#ifndef STEP_PARSER_OBJECTEXPRESSIONPARSER_H
#define STEP_PARSER_OBJECTEXPRESSIONPARSER_H

#include "../structures/StepReaderConfig.h"
#include "../structures/Expression.h"

#include "../utils/StringUtils.h"
#include "../utils/VectorUtils.h"

#include "../extractors/AbstractArgumentsExtractor.h"

#include "SimpleExpressionParser.h"
#include "BaseExpressionParser.h"

using namespace std;


class ObjectExpressionParser: public BaseExpressionParser {
public:
    ObjectExpressionParser(
            SimpleExpressionParser * simpleExpressionParser,
            AbstractArgumentsExtractor * argumentsExtractor
    );

    ~ObjectExpressionParser() {
        delete argumentsExtractor;
        delete simpleExpressionParser;
    }

    Expression parse(string inputData) override;

private:
    VectorUtils vectorUtils;
    AbstractArgumentsExtractor * argumentsExtractor;
    SimpleExpressionParser * simpleExpressionParser;
};


#endif STEP_PARSER_OBJECTEXPRESSIONPARSER_H
