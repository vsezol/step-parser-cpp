#ifndef STEP_PARSER_TREEEXPRESSIONTOJSONCONVERTER_H
#define STEP_PARSER_TREEEXPRESSIONTOJSONCONVERTER_H

#include <string>
#include <map>
#include <vector>

#include "../../../dependencies/json/single_include/nlohmann/json.hpp"
#include "../structures/TreeExpression.h"
#include "../structures/ExecutionConfig.h"
#include "../structures/StepReaderConfig.h"

class TreeExpressionToJsonConverter {
public:
    TreeExpressionToJsonConverter(ExecutionConfig &executionConfig, StepReaderConfig readerConfig);

    string convert(TreeExpression expression);

    nlohmann::json convertToJSON(TreeExpression expression);
private:
    nlohmann::json convertStringVectorToJson(vector<string> vec);

    nlohmann::json convertTreeExpressionVectorToJson(vector<TreeExpression> vec);

    ExecutionConfig executionConfig;

    StepReaderConfig readerConfig;
};


#endif //STEP_PARSER_TREEEXPRESSIONTOJSONCONVERTER_H
