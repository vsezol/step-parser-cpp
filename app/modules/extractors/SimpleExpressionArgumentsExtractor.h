#ifndef STEP_PARSER_SIMPLEEXPRESSIONARGUMENTSEXTRACTOR_H
#define STEP_PARSER_SIMPLEEXPRESSIONARGUMENTSEXTRACTOR_H

#include <string>
#include <vector>

#include "../structures/StepReaderConfig.h"
#include "AbstractArgumentsExtractor.h"

struct CutExpressionResult {
    vector<string> expressions;
    vector<vector<int>> expressionsScopes;
    string content;
};

class SimpleExpressionArgumentsExtractor: public AbstractArgumentsExtractor {
public:
    SimpleExpressionArgumentsExtractor(StepReaderConfig stepReaderConfig);

    vector<string> extract(string content) override;

private:
    CutExpressionResult cutExpressions(string content);

    vector<int> findFullScopeByCallScope(string content, vector<int> scope);

    vector<int> findCallScopeRange(string content);

    bool checkExpressionExistsByScope(vector<int> scope);
};


#endif STEP_PARSER_SIMPLEEXPRESSIONARGUMENTSEXTRACTOR_H
