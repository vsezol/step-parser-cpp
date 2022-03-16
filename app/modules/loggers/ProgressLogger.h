#ifndef STEP_PARSER_PROGRESSLOGGER_H
#define STEP_PARSER_PROGRESSLOGGER_H

#include <string>

using namespace std;

class ProgressLogger {
public:
    ProgressLogger(string* stages, int stagesCount);

    ~ProgressLogger();

    void logCurrentStage();

    void toNextStage();

    void logStageByIndex(int stageIndex);

private:
    int stagesCount;
    int currentStageIndex = 0;
    string* stages;
};


#endif //STEP_PARSER_PROGRESSLOGGER_H
