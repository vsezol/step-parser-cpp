cmake_minimum_required(VERSION 3.17)
project(step_parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(step_parser main.cpp modules/StringUtils.cpp modules/StringUtils.h modules/FileReader.cpp modules/FileReader.h modules/VectorUtils.cpp modules/VectorUtils.h modules/SectionStepExtractor.cpp modules/SectionStepExtractor.h modules/StepReaderConfig.h modules/ExpressionsDataStepExtractor.cpp modules/ExpressionsDataStepExtractor.h)