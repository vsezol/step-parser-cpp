#ifndef STEP_PARSER_STRINGUTILS_H
#define STEP_PARSER_STRINGUTILS_H

#include <string>
#include <vector>

using namespace std;

class StringUtils {
public:
    static vector<string> split (string str, string delimiter);

    static string removeFirstElement(string str);

    static string removeLastElement(string str);

    static string removeEnds(string str);

    static string trimByChar(string str, char chr);

    static string charToString(char chr);

    static bool hasSubstring(string main, string sub);
};


#endif STEP_PARSER_STRINGUTILS_H
