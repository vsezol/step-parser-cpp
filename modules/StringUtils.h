#ifndef STEP_PARSER_STRINGUTILS_H
#define STEP_PARSER_STRINGUTILS_H

#include <string>
#include <vector>

using namespace std;

class StringUtils {
public:
    vector<string> split (string str, string delimiter);

    string removeFirstElement(string str);

    string removeLastElement(string str);

    string removeEnds(string str);

    string trimByChar(string str, char chr);
};


#endif STEP_PARSER_STRINGUTILS_H
