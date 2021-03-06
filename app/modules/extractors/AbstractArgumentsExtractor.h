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

    virtual vector<string> extract(string content) = 0;

protected:
    StepReaderConfig stepReaderConfig;
};


#endif STEP_PARSER_ABSTRACTARGUMENTSEXTRACTOR_H
