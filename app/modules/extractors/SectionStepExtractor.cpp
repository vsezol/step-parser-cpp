#include "SectionStepExtractor.h"

SectionStepExtractor::SectionStepExtractor(StepReaderConfig config, string content): config(config) {
  sections = StringUtils::split(content, config.END_SECTION_KEYWORD);
}

string SectionStepExtractor::extractSectionContent(string keyword) {
  string section = extractSectionByKeyword(keyword);

  return StringUtils::split(section, wrapKeyword(keyword))[1];
}

string SectionStepExtractor::extractSectionByKeyword(string keyword) {
  return sections[getSectionIndexByKeyword(keyword)];
}

int SectionStepExtractor::getSectionIndexByKeyword(string keyword) {
  for (int i = 0; i < sections.size(); i++) {
    string section = sections[i];

    if (section.find(keyword) != string::npos) {
      return i;
    }
  }

  return -1;
}

string SectionStepExtractor::wrapKeyword(string keyword) {
  return keyword + config.STRING_DIVIDER;
}