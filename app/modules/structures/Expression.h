#ifndef STEP_PARSER_EXPRESSION_H
#define STEP_PARSER_EXPRESSION_H

#include <vector>
#include <string>
#include "BaseExpression.h"

using namespace std;

struct Expression : public BaseExpression {
    vector<Expression> expressions;
    vector<string> children;
    vector<Expression> arrays;
};

#endif STEP_PARSER_EXPRESSION_H
