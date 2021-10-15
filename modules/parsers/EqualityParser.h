#ifndef STEP_PARSER_EQUALITYPARSER_H
#define STEP_PARSER_EQUALITYPARSER_H

#include <vector>
#include <map>
#include "../structures/StepReaderConfig.h"
#include "../utils/StringUtils.h"
#include "AbstractParser.h"

using namespace std;

class EqualityParser: public AbstractParser<string, vector<string>> {
public:
    EqualityParser(StepReaderConfig readerConfig);

    vector<string> parse(string inputData) override;

private:
    StepReaderConfig readerConfig;
    StringUtils stringUtils;

    string extractNumber(string inputData);
    string extractExpression(string inputData);
};


#endif STEP_PARSER_EQUALITYPARSER_H
