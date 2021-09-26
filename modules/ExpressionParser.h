#ifndef STEP_PARSER_EXPRESSIONPARSER_H
#define STEP_PARSER_EXPRESSIONPARSER_H

#include <string>
#include <vector>

#include "StepReaderConfig.h"
#include "Expression.h"
#include "StringUtils.h"

struct CutExpressionResult {
    vector<string> expressions;
    string content;
};

class ExpressionParser {
public:
    ExpressionParser(string stringExpression, StepReaderConfig readerConfig);
    void parse();

    Expression getExpression();

private:
    string stringExpression;
    Expression expression;

    StringUtils stringUtils;
    StepReaderConfig readerConfig;

    int getExpressionNameEndIndex(string expression);

    bool checkIsExpression(string expression);

    bool checkIsLink(string expression);

    vector<string> processArguments(string content);

    CutExpressionResult cutExpressions(string content);

    bool checkExpressionExistsByScope(vector<int> scope);

    vector<int> findFullScopeByCallScope(string content, vector<int> scope);

    vector<int> findCallScopeRange(string content);
};

#endif STEP_PARSER_EXPRESSIONPARSER_H
