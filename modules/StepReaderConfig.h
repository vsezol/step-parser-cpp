#ifndef STEP_PARSER_STEPREADERCONFIG_H
#define STEP_PARSER_STEPREADERCONFIG_H

#include <string>

using namespace std;

const struct StepReaderConfig {
    string END_SECTION_KEYWORD;
    string HEADER_KEYWORD;
    string DATA_KEYWORD;
    string STRING_DIVIDER;
    char OPEN_SCOPE_SYMBOL;
    char CLOSE_SCOPE_SYMBOL;
    char ARGUMENTS_DIVIDER_SYMBOL;
    char LINK_BEGIN_SYMBOL;
};

#endif STEP_PARSER_STEPREADERCONFIG_H
