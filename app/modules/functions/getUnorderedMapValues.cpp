#include <vector>
#include <unordered_map>

using namespace std;

template<typename T, typename U>
vector<U> getUnorderedMapValues(unordered_map<T, U> inputMap) {
  vector<U> mapValues;

  for (typename unordered_map<T, U>::iterator tableItem = inputMap.begin();
       tableItem != inputMap.end(); tableItem++) {
    mapValues.push_back(tableItem->second);
  }

  return mapValues;
}