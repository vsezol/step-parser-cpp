#ifndef STEP_PARSER_EXPRESSIONTOVZCONVERTER_H
#define STEP_PARSER_EXPRESSIONTOVZCONVERTER_H

#include <string>
#include "../structures/Expression.h"
#include "../structures/VzConfig.h"

using namespace std;

const VzConfig vzConfig = {
        '=',
        '.',
        '"',
        ' ',
        4
};

class ExpressionToVzConverter {
public:
    ExpressionToVzConverter(Expression expression, VzConfig vzConfig, int currTabsCount = 0) : expression(expression),
                                                                                               vzConfig(vzConfig),
                                                                                               currTabsCount(
                                                                                                       currTabsCount) {}

    string convert() {
      string content = "";

      content += nestedField(expression.name);

      currTabsCount++;

      if (expression.links.size() > 0) {
        content += nestedField("links", expression.links);
      }
      if (expression.values.size() > 0) {
        content += nestedField("values", expression.values);
      }
      if (expression.arrays.size() > 0) {
        content += nestedField("arrays");
      }

      for (int i = 0; i < expression.expressions.size(); i++) {
        ExpressionToVzConverter converter = ExpressionToVzConverter(expression.expressions[i], vzConfig, currTabsCount);
        content += converter.convert();
      }

      return content;
    }

private:
    Expression expression;
    VzConfig vzConfig;
    int currTabsCount;

    string str(string value) {
      return vzConfig.STRING_QUOTE_SYMBOL + value + vzConfig.STRING_QUOTE_SYMBOL;
    }

    string arr(vector<string> values, int tabsCount) {
      string content = "";

      for (int i = 0; i < values.size(); i++) {
        content = content + getTabs(tabsCount) + vzConfig.EQUAL_SYMBOL + " " + values[i] + '\n';
      }

      return content;
    }

    string nestedField(string name, string value = "") {
      string content = getTabs();
      content += vzConfig.NESTING_SYMBOL;
      content += vzConfig.SPACE_SYMBOL;
      content += name;

      if (value.length() > 0) {
        content += vzConfig.SPACE_SYMBOL;
        content += vzConfig.EQUAL_SYMBOL;
        content += vzConfig.SPACE_SYMBOL;
        content += value;
      }

      content += '\n';

      return content;
    }

    string nestedField(string name, vector<string> values) {
      string content = getTabs();
      content += vzConfig.NESTING_SYMBOL;
      content += vzConfig.SPACE_SYMBOL;
      content += name;
      content += '\n';

      content += arr(values, 1);

      return content;
    }

    string getTabs(int additionalTabsCount = -1) {
      int spacesCount = currTabsCount * vzConfig.TAB_SIZE;

      if (additionalTabsCount != -1) {
        spacesCount += additionalTabsCount * vzConfig.TAB_SIZE;
      }

      string tabs = "";
      for (int i = 0; i < spacesCount; i++) {
        tabs += vzConfig.SPACE_SYMBOL;
      }

      return tabs;
    }
};


#endif STEP_PARSER_EXPRESSIONTOVZCONVERTER_H
