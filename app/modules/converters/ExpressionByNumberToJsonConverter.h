#ifndef STEP_PARSER_EXPRESSIONBYNUMBERTOJSONCONVERTER_H
#define STEP_PARSER_EXPRESSIONBYNUMBERTOJSONCONVERTER_H

#include <string>
#include <map>

#include "../../../dependencies/json/single_include/nlohmann/json.hpp"
#include "../structures/Expression.h"
#include "ExpressionToJsonConverter.h"

using namespace std;

class ExpressionByNumberToJsonConverter {
public:
    ExpressionByNumberToJsonConverter(ExpressionToJsonConverter * expressionToJsonConverter);

    ~ExpressionByNumberToJsonConverter() {
      delete expressionToJsonConverter;
    }

    string convert(map<int, Expression> expressionByNumber);

    nlohmann::json convertToJSON(map<int, Expression> expressionByNumber);

private:
    ExpressionToJsonConverter * expressionToJsonConverter;
};


#endif //STEP_PARSER_EXPRESSIONBYNUMBERTOJSONCONVERTER_H
