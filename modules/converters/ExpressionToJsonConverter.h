#ifndef STEP_PARSER_EXPRESSIONTOJSONCONVERTER_H
#define STEP_PARSER_EXPRESSIONTOJSONCONVERTER_H

#include <iostream>
#include "../structures/Expression.h"
#include "../utils/VectorUtils.h"
#include "../../libs/json/single_include/nlohmann/json.hpp"

class ExpressionToJsonConverter {
public:
    ExpressionToJsonConverter() {};

    string convert(Expression expression) {
      return convertToJSON(expression).dump();
    }

private:
    nlohmann::json convertToJSON(Expression expression) {
      nlohmann::json j;
      j["name"] = expression.name;
      j["number"] = expression.number;

      j["values"] = convertVectorToJson(expression.values);
      j["links"] = convertVectorToJson(expression.links);
      j["arrays"] = convertVectorToJson(expression.arrays);

      if (expression.expressions.size() > 0) {
        vector<nlohmann::json> nestedExpressions;

        for (int i = 0; i < expression.expressions.size(); i++) {
          nestedExpressions.push_back(convertToJSON(expression.expressions[i]));
        }

        j["expressions"] = convertVectorToJson(nestedExpressions);
      }

      return j;
    }

    template<typename T>
    nlohmann::json convertVectorToJson(vector<T> vec) {
      nlohmann::json j;

      for (int i = 0; i < vec.size(); i++) {
        j.push_back(vec[i]);
      }

      return j;
    }
};


#endif STEP_PARSER_EXPRESSIONTOJSONCONVERTER_H
