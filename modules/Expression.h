#ifndef STEP_PARSER_EXPRESSION_H
#define STEP_PARSER_EXPRESSION_H


struct Expression {
    string name;
    vector<Expression> expressions;
    vector<string> values;
    vector<string> links;
};

#endif STEP_PARSER_EXPRESSION_H
