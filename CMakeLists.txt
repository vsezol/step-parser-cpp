cmake_minimum_required(VERSION 3.17)
project(step_parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(step_parser main.cpp modules/utils/StringUtils.cpp modules/utils/StringUtils.h modules/readers/FileReader.cpp modules/readers/FileReader.h modules/utils/VectorUtils.cpp modules/utils/VectorUtils.h modules/extractors/SectionStepExtractor.cpp modules/extractors/SectionStepExtractor.h modules/structures/StepReaderConfig.h modules/extractors/ExpressionsDataStepExtractor.cpp modules/extractors/ExpressionsDataStepExtractor.h modules/structures/Expression.h modules/parsers/ExpressionParser.cpp modules/parsers/ExpressionParser.h modules/structures/VzConfig.h modules/converters/ExpressionToVzConverter.h)