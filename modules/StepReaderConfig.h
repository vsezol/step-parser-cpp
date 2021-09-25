#ifndef STEP_PARSER_STEPREADERCONFIG_H
#define STEP_PARSER_STEPREADERCONFIG_H

#include <string>

using namespace std;

const struct StepReaderConfig {
    string END_SECTION_KEYWORD;
    string HEADER_KEYWORD;
    string DATA_KEYWORD;
    string STRING_DIVIDER;
};

#endif STEP_PARSER_STEPREADERCONFIG_H
