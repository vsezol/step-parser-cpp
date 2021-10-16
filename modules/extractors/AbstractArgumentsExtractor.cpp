#include "AbstractArgumentsExtractor.h"
#include <iostream>

AbstractArgumentsExtractor::AbstractArgumentsExtractor(StepReaderConfig stepReaderConfig): stepReaderConfig(stepReaderConfig) {
  stringUtils = StringUtils();
  vectorUtils = VectorUtils();
}