#include "EqualitiesExtractor.h"

EqualitiesExtractor::EqualitiesExtractor(StepReaderConfig stepReaderConfig) : stepReaderConfig(stepReaderConfig) {
}

vector<string> EqualitiesExtractor::extract(string content) {
  vector<string> equalities = StringUtils::split(content, StringUtils::charToString(stepReaderConfig.STRING_DIVIDER));
  equalities.pop_back();

  return equalities;
}