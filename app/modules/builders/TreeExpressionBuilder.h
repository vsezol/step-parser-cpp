#ifndef STEP_PARSER_TREEEXPRESSIONBUILDER_H
#define STEP_PARSER_TREEEXPRESSIONBUILDER_H

#include <unordered_map>

#include "../structures/StepReaderConfig.h"
#include "../structures/TreeExpression.h"
#include "../structures/Expression.h"

class TreeExpressionBuilder {
public:
  TreeExpressionBuilder(StepReaderConfig readerConfig, unordered_map<short, Expression> &expressionByNumber);

  TreeExpression build(Expression &expression);
private:
    StepReaderConfig readerConfig;

    unordered_map<short, Expression> expressionByNumber;
};


#endif //STEP_PARSER_TREEEXPRESSIONBUILDER_H
