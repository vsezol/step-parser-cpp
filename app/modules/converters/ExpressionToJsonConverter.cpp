#include "ExpressionToJsonConverter.h"
#include <iostream>

string ExpressionToJsonConverter::convert(Expression expression) {
  return convertToJSON(expression).dump();
}

nlohmann::json ExpressionToJsonConverter::convertToJSON(Expression expression) {
  nlohmann::json j;
  j["name"] = expression.name;
  j["number"] = expression.number;

  j["values"] = convertPrimitiveVectorToJson(expression.values);
  j["links"] = convertPrimitiveVectorToJson(expression.links);

  if (expression.arrays.size() > 0) {
    vector<nlohmann::json> arrays;

    for (int i = 0; i < expression.expressions.size(); i++) {
      arrays.push_back(convertToJSON(expression.arrays[i]));
    }

    j["arrays"] = convertPrimitiveVectorToJson(arrays);
  }

  if (expression.expressions.size() > 0) {
    vector<nlohmann::json> nestedExpressions;

    for (int i = 0; i < expression.expressions.size(); i++) {
      nestedExpressions.push_back(convertToJSON(expression.expressions[i]));
    }

    j["expressions"] = convertPrimitiveVectorToJson(nestedExpressions);
  }

  return j;
}

template<typename T>
nlohmann::json ExpressionToJsonConverter::convertPrimitiveVectorToJson(vector<T> vec) {
  nlohmann::json j;

  for (int i = 0; i < vec.size(); i++) {
    j.push_back(vec[i]);
  }

  return j;
}