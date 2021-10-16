#include "EqualitiesExtractor.h"

EqualitiesExtractor::EqualitiesExtractor(StepReaderConfig stepReaderConfig) : stepReaderConfig(stepReaderConfig) {
  StringUtils stringUtils = StringUtils();
}

vector<string> EqualitiesExtractor::extract(string content) {
  vector<string> equalities = stringUtils.split(content, stringUtils.charToString(stepReaderConfig.STRING_DIVIDER));
  equalities.pop_back();

  return equalities;
}