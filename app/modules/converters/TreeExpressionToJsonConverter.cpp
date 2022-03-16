#include "TreeExpressionToJsonConverter.h"
#include "../utils/StringUtils.h"

TreeExpressionToJsonConverter::TreeExpressionToJsonConverter(
        ExecutionConfig &executionConfig,
        StepReaderConfig readerConfig
) : executionConfig(executionConfig), readerConfig(readerConfig) {}

string TreeExpressionToJsonConverter::convert(TreeExpression expression) {
  return convertToJSON(expression).dump();
}

nlohmann::json TreeExpressionToJsonConverter::convertToJSON(TreeExpression expression) {
  nlohmann::json j;

  if (executionConfig.isShowEmpty || !expression.values.empty()) {
    j["values"] = convertStringVectorToJson(expression.values);
  }

  if (executionConfig.isShowEmpty || !expression.arrays.empty()) {
    j["arrays"] = convertTreeExpressionVectorToJson(expression.arrays);
  }

  if (executionConfig.isShowEmpty || !expression.children.empty()) {
    j["children"] = convertTreeExpressionVectorToJson(expression.children);
  }

  if (executionConfig.isShowEmpty || !expression.expressions.empty()) {
    j["expressions"] = convertTreeExpressionVectorToJson(expression.expressions);
  }

  if (executionConfig.isShowEmpty || !expression.name.empty()) {
    j["name"] = expression.name;
  }

  if (executionConfig.isShowAllNumbers || expression.number > 0) {
    j["number"] = expression.number;
  }

  return j;
}

nlohmann::json TreeExpressionToJsonConverter::convertStringVectorToJson(vector<string> vec) {
  nlohmann::json j;

  for (int i = 0; i < vec.size(); i++) {
    string element = vec[i];

    if (
            !executionConfig.isShowEmpty &&
            (
                    element.empty() ||
                    element == StringUtils::charToString(readerConfig.EMPTY_ARGUMENT_SYMBOL)
            )
    ) {
      continue;
    }

    j.push_back(vec[i]);
  }

  return j;
}

nlohmann::json TreeExpressionToJsonConverter::convertTreeExpressionVectorToJson(vector<TreeExpression> vec) {
  nlohmann::json j;

  for (int i = 0; i < vec.size(); i++) {

    j.push_back(TreeExpressionToJsonConverter(executionConfig, readerConfig).convertToJSON(vec[i]));
  }

  return j;
}