#include <iostream>
#include "VectorUtils.h"

using namespace std;

void VectorUtils::printStrings(vector<string> arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << '\t';
  }

  cout << endl;
}

vector<string> VectorUtils::removeEmptyStrings(vector<string> arr) {
  vector<string> newArray;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i].length() > 0) {
      newArray.push_back(arr[i]);
    }
  }

  return newArray;
}