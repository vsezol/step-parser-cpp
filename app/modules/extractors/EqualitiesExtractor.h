#ifndef STEP_PARSER_EQUALITIESEXTRACTOR_H
#define STEP_PARSER_EQUALITIESEXTRACTOR_H

#include <string>
#include <vector>
#include "../utils/StringUtils.h"
#include "../structures/StepReaderConfig.h"

class EqualitiesExtractor {
public:
    EqualitiesExtractor(StepReaderConfig stepReaderConfig);

    vector<string> extract(string content);

private:
    StepReaderConfig stepReaderConfig;
};


#endif STEP_PARSER_EQUALITIESEXTRACTOR_H
