#ifndef STEP_PARSER_SECTIONSTEPEXTRACTOR_H
#define STEP_PARSER_SECTIONSTEPEXTRACTOR_H

#include <string>
#include <vector>
#include "StepReaderConfig.h"
#include "StringUtils.h"

class SectionStepExtractor {
public:
    SectionStepExtractor(StepReaderConfig config, string content);

    string extractSectionContent(string keyword);

private:
    vector<string> sections;
    StepReaderConfig config;

    StringUtils stringUtils;

    string extractSectionByKeyword(string keyword);

    int getSectionIndexByKeyword(string keyword);

    string wrapKeyword(string keyword);
};

#endif STEP_PARSER_SECTIONSTEPEXTRACTOR_H
