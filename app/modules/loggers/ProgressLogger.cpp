#include "ProgressLogger.h"
#include <iostream>

ProgressLogger::ProgressLogger(string *stages, int stagesCount) : stages(stages), stagesCount(stagesCount) {}

ProgressLogger::~ProgressLogger() {
  delete[] stages;
}

void ProgressLogger::logCurrentStage() {
  logStageByIndex(currentStageIndex);
}

void ProgressLogger::toNextStage() {
  if (currentStageIndex + 1 > stagesCount) {
    return;
  }
  currentStageIndex++;
}

void ProgressLogger::logStageByIndex(int stageIndex) {
  cout << to_string(stageIndex + 1) + "/" + to_string(stagesCount) << '\t' << stages[stageIndex] << endl;
}
