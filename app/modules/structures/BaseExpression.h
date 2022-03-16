#ifndef STEP_PARSER_BASEEXPRESSION_H
#define STEP_PARSER_BASEEXPRESSION_H

#include <vector>
#include <string>

using namespace std;

struct BaseExpression {
    string name;
    int number;
    vector<string> values;
};

#endif //STEP_PARSER_BASEEXPRESSION_H
