#ifndef STEP_PARSER_OBJECTARGUMENTSEXTRACTOR_H
#define STEP_PARSER_OBJECTARGUMENTSEXTRACTOR_H

#include <string>
#include <vector>

#include "../utils/StringUtils.h"
#include "../utils/VectorUtils.h"
#include "../structures/StepReaderConfig.h"
#include "AbstractArgumentsExtractor.h"

using namespace std;

class ObjectArgumentsExtractor : public AbstractArgumentsExtractor {
public:
    ObjectArgumentsExtractor(StepReaderConfig stepReaderConfig);

    virtual vector<string> extract(string content);
};


#endif STEP_PARSER_OBJECTARGUMENTSEXTRACTOR_H
