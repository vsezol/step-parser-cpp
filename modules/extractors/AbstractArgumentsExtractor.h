#ifndef STEP_PARSER_ABSTRACTARGUMENTSEXTRACTOR_H
#define STEP_PARSER_ABSTRACTARGUMENTSEXTRACTOR_H

#include <string>
#include <vector>

#include "../utils/StringUtils.h"
#include "../utils/VectorUtils.h"
#include "../structures/StepReaderConfig.h"


class AbstractArgumentsExtractor {
public:
    AbstractArgumentsExtractor(StepReaderConfig stepReaderConfig);

    virtual vector<string> extract(string content);

protected:
    StepReaderConfig stepReaderConfig;
    StringUtils stringUtils;
    VectorUtils vectorUtils;
};


#endif STEP_PARSER_ABSTRACTARGUMENTSEXTRACTOR_H
