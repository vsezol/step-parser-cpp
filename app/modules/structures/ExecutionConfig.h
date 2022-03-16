#ifndef STEP_PARSER_EXECUTIONCONFIG_H
#define STEP_PARSER_EXECUTIONCONFIG_H

struct ExecutionConfig {
    string inputPath;
    string outputPath;
    string mode; // flat, tree
    bool isShowEmpty;
    bool isShowAllNumbers;
    string filterBy;

    void updateByArguments(vector<string> arguments) {
      for (int i = 0; i < arguments.size(); i++) {
        string arg = arguments[i];

        string nextArg = "";
        if (i < arguments.size() - 1) {
          nextArg = arguments[i + 1];
        }

        if (arg == "--input" || arg == "-I") {
          inputPath = nextArg;
        } else if (arg == "--output" || arg == "-O") {
          outputPath = nextArg;
        } else if (arg == "--mode" || arg == "-M") {
          mode = nextArg;
        } else if (arg == "--show-empty" || arg == "-SE") {
          isShowEmpty = true;
        } else if (arg == "--show-all-numbers" || arg == "-SAN") {
          isShowAllNumbers = true;
        } else if (arg == "--filter-by" || arg == "-FB") {
          filterBy = nextArg;
        }
      }
    }
};

#endif STEP_PARSER_EXECUTIONCONFIG_H
