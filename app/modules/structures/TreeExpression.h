#ifndef STEP_PARSER_TREEEXPRESSION_H
#define STEP_PARSER_TREEEXPRESSION_H

#include <string>
#include "BaseExpression.h"

using namespace std;

struct TreeExpression : public BaseExpression {
    vector<TreeExpression> expressions;
    vector<TreeExpression> children;
    vector<TreeExpression> arrays;
};

#endif //STEP_PARSER_TREEEXPRESSION_H
