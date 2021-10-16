#ifndef STEP_PARSER_OBJECTEXPRESSIONARGUMENTSEXTRACTOR_H
#define STEP_PARSER_OBJECTEXPRESSIONARGUMENTSEXTRACTOR_H

#include <string>
#include <vector>

#include "../structures/StepReaderConfig.h"
#include "AbstractArgumentsExtractor.h"

using namespace std;

class ObjectExpressionArgumentsExtractor : public AbstractArgumentsExtractor {
public:
    ObjectExpressionArgumentsExtractor(StepReaderConfig stepReaderConfig);

    vector<string> extract(string content) override;
};


#endif STEP_PARSER_OBJECTEXPRESSIONARGUMENTSEXTRACTOR_H
