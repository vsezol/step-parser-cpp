#include "AbstractArgumentsExtractor.h"
#include <iostream>

AbstractArgumentsExtractor::AbstractArgumentsExtractor(StepReaderConfig stepReaderConfig): stepReaderConfig(stepReaderConfig) {
  stringUtils = StringUtils();
  vectorUtils = VectorUtils();
}

vector<string> AbstractArgumentsExtractor::extract(string content) {
  vector<string> voidVector;
  return voidVector;
}