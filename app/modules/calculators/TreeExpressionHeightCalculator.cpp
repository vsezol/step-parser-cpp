#include "TreeExpressionHeightCalculator.h"

int TreeExpressionHeightCalculator::byChildren(TreeExpression &treeExpression) {
  if (treeExpression.children.empty()) {
    return 0;
  }

  int maxHeight = 0;

  for (int i = 0; i < treeExpression.children.size(); i++) {
    int currentHeight = byChildren(treeExpression.children[i]);

    if (currentHeight > maxHeight) {
      maxHeight = currentHeight;
    }
  }

  return 1 + maxHeight;
}
