#ifndef STEP_PARSER_EQUALITYPARTSPARSER_H
#define STEP_PARSER_EQUALITYPARTSPARSER_H

#include <vector>
#include "AbstractParser.h"
#include "../structures/StepReaderConfig.h"
#include "../utils/StringUtils.h"

using namespace std;

class EqualityPartsParser: public AbstractParser<string, vector<string>> {
public:
    EqualityPartsParser(StepReaderConfig readerConfig);

    vector<string> parse(string inputData) override;

private:
    StepReaderConfig readerConfig;
    StringUtils stringUtils;

    string extractNumber(string inputData);
    string extractExpression(string inputData);
};


#endif STEP_PARSER_EQUALITYPARTSPARSER_H
