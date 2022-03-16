#include "TreeExpressionBuilder.h"
#include "../utils/StringUtils.h"

TreeExpressionBuilder::TreeExpressionBuilder(
        StepReaderConfig readerConfig,
        unordered_map<short, Expression> &expressionByNumber
) :
readerConfig(readerConfig),
expressionByNumber(expressionByNumber) {}

TreeExpression TreeExpressionBuilder::build(Expression &expression) {
  Expression rootExpression = expression;

  TreeExpression result;
  result.name = rootExpression.name;
  result.number = rootExpression.number;
  result.values = rootExpression.values;

  if (rootExpression.expressions.size() >= 0) {
    vector<TreeExpression> treeExpressions;
    treeExpressions.reserve(rootExpression.expressions.size());

    for (int i = 0; i < rootExpression.expressions.size(); i++) {
      Expression currentExpression = rootExpression.expressions[i];

      TreeExpression item = build(currentExpression);
      treeExpressions.push_back(item);

      // типо если номер больше нуля то через дерево собирать,
      // а если хуевый номер то пушить просто так, я бухой кстати)) сука пизда член
      // си плюс плюс в рот ебал
//      treeExpressions.push_back(currentExpression);

//      TreeExpression item = TreeExpressionBuilder(readerConfig, expressionByNumber).build(i);
    }

    result.expressions = treeExpressions;
  }

  if (rootExpression.arrays.size() >= 0) {
    vector<TreeExpression> treeExpressions;
    treeExpressions.reserve(rootExpression.arrays.size());

    for (int i = 0; i < rootExpression.arrays.size(); i++) {
      Expression currentArray = rootExpression.arrays[i];

      TreeExpression item = build(currentArray);
      treeExpressions.push_back(item);
    }

    result.arrays = treeExpressions;
  }

  if (rootExpression.children.size() >= 0) {
    vector<TreeExpression> treeExpressions;
    treeExpressions.reserve(rootExpression.children.size());

    for (int i = 0; i < rootExpression.children.size(); i++) {
      string childLink = rootExpression.children[i];

      int childNumber = stoi(
              StringUtils::split(childLink, StringUtils::charToString(readerConfig.LINK_BEGIN_SYMBOL))[1]);

      TreeExpression childTreeExp = build(expressionByNumber[childNumber]);
      treeExpressions.push_back(childTreeExp);
    }

    result.children = treeExpressions;
  }

  return result;
}