#include "ExpressionByNumberToJsonConverter.h"
#include <iostream>
#include <string>

using namespace std;

ExpressionByNumberToJsonConverter::ExpressionByNumberToJsonConverter(
        ExpressionToJsonConverter *expressionToJsonConverter): expressionToJsonConverter(expressionToJsonConverter) {
}

string ExpressionByNumberToJsonConverter::convert(map<int, Expression> expressionByNumber) {
  return convertToJSON(expressionByNumber).dump();
}

nlohmann::json ExpressionByNumberToJsonConverter::convertToJSON(map<int, Expression> expressionByNumber) {
  nlohmann::json j;

  map<int, Expression>::iterator item;

  for (item = expressionByNumber.begin(); item != expressionByNumber.end(); item++) {
    j[to_string(item->first)] = expressionToJsonConverter->convertToJSON(item->second);
  }

  return j;
}
