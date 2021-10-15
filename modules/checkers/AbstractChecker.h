#ifndef STEP_PARSER_ABSTRACTCHECKER_H
#define STEP_PARSER_ABSTRACTCHECKER_H

template<typename Content>
class AbstractChecker {
public:
    virtual bool check(Content content) = 0;
};


#endif STEP_PARSER_ABSTRACTCHECKER_H
