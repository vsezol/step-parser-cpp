#ifndef STEP_PARSER_EXPRESSIONPARSER_H
#define STEP_PARSER_EXPRESSIONPARSER_H

#include <string>
#include <vector>

#include "../structures/StepReaderConfig.h"
#include "../structures/Expression.h"
#include "../utils/StringUtils.h"

struct CutExpressionResult {
    vector<string> expressions;
    vector<vector<int>> expressionsScopes;
    string content;
};

class ExpressionParser {
public:
    ExpressionParser(string stringExpression, StepReaderConfig readerConfig);
    void parse();

    Expression getRootExpression();

private:
    string stringExpression;
    Expression rootExpression;

    StringUtils stringUtils;
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

#endif STEP_PARSER_EXPRESSIONPARSER_H
