#ifndef STEP_PARSER_SIMPLEEXPRESSIONPARSER_H
#define STEP_PARSER_SIMPLEEXPRESSIONPARSER_H

#include <string>
#include <vector>

#include "../structures/StepReaderConfig.h"
#include "../structures/Expression.h"
#include "../utils/StringUtils.h"
#include "ExpressionParser.h"

struct CutExpressionResult {
    vector<string> expressions;
    vector<vector<int>> expressionsScopes;
    string content;
};

class SimpleExpressionParser : public ExpressionParser {
public:
    SimpleExpressionParser(StepReaderConfig readerConfig);

    Expression parse(string inputData) override;

private:
    string stringExpression;

    StepReaderConfig readerConfig;

    int getExpressionNameEndIndex(string expression);

    bool checkIsExpression(string expression);

    bool checkIsLink(string expression);

    bool checkIsArray(string expression);

    vector<string> processArguments(string content);

    CutExpressionResult cutExpressions(string content);

    bool checkExpressionExistsByScope(vector<int> scope);

    vector<int> findFullScopeByCallScope(string content, vector<int> scope);

    vector<int> findCallScopeRange(string content);
};

#endif STEP_PARSER_SIMPLEEXPRESSIONPARSER_H
