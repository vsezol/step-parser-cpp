#ifndef STEP_PARSER_EXPRESSION_H
#define STEP_PARSER_EXPRESSION_H

#include <vector>
#include <string>

using namespace std;

struct Expression {
    string name;
    int number;
    vector<Expression> expressions;
    vector<string> values;
    vector<string> links;
    vector<Expression> arrays;
};

#endif STEP_PARSER_EXPRESSION_H
