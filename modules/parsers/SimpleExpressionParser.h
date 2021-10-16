#ifndef STEP_PARSER_SIMPLEEXPRESSIONPARSER_H
#define STEP_PARSER_SIMPLEEXPRESSIONPARSER_H

#include <string>
#include <vector>

#include "../structures/StepReaderConfig.h"
#include "../structures/Expression.h"
#include "ExpressionParser.h"
#include "../extractors/AbstractArgumentsExtractor.h"

class SimpleExpressionParser : public ExpressionParser {
public:
    SimpleExpressionParser(StepReaderConfig readerConfig, AbstractArgumentsExtractor * argumentsExtractor);

    ~SimpleExpressionParser() {
      delete argumentsExtractor;
    };

    Expression parse(string inputData) override;

private:
    StepReaderConfig readerConfig;

    AbstractArgumentsExtractor * argumentsExtractor;

    int getExpressionNameEndIndex(string expression);

    bool checkIsExpression(string expression);

    bool checkIsLink(string expression);

    bool checkIsArray(string expression);
};

#endif STEP_PARSER_SIMPLEEXPRESSIONPARSER_H
