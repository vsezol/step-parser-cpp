#ifndef STEP_PARSER_ABSTRACTPARSER_H
#define STEP_PARSER_ABSTRACTPARSER_H


template<typename InputData, typename ParsedData>
class AbstractParser {
public:
    virtual ParsedData parse(InputData inputData) = 0;
};


#endif STEP_PARSER_ABSTRACTPARSER_H
