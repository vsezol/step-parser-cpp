#ifndef STEP_PARSER_EXPRESSIONTOJSONCONVERTER_H
#define STEP_PARSER_EXPRESSIONTOJSONCONVERTER_H

#include "../../../dependencies/json/single_include/nlohmann/json.hpp"
#include "../structures/Expression.h"
#include "../utils/VectorUtils.h"

class ExpressionToJsonConverter {
public:
    ExpressionToJsonConverter() {};

    string convert(Expression expression);

    nlohmann::json convertToJSON(Expression expression);
private:
    template<typename T>
    nlohmann::json convertPrimitiveVectorToJson(vector<T> vec);
};


#endif //STEP_PARSER_EXPRESSIONTOJSONCONVERTER_H
