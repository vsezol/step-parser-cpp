#ifndef STEP_PARSER_TREEEXPRESSIONHEIGHTCALCULATOR_H
#define STEP_PARSER_TREEEXPRESSIONHEIGHTCALCULATOR_H


#include "../structures/TreeExpression.h"

class TreeExpressionHeightCalculator {
public:
    static int byChildren(TreeExpression &treeExpression);
};


#endif //STEP_PARSER_TREEEXPRESSIONHEIGHTCALCULATOR_H
