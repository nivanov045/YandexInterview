// Task: check to strings for similarity (can we have one string from another using one additional symbol or by
// deleting symbol or by changing to another symbol)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool areSimilar(const string& lStr, const string& rStr) {
  int lSize = lStr.size();
  int rSize = rStr.size();
  if (abs(lSize - rSize) > 1)
    return false;
  if (lSize == rSize) {
    int idx = 0;
    int mistakes = 0;
    while (idx < lSize && mistakes < 2) {
      mistakes += lStr[idx] == rStr[idx] ? 0 : 1;
      ++idx;
    }
    if (idx == lSize && mistakes < 2)
      return true;
  }
  else {
    const string& bigger = (lSize < rSize) ? rStr : lStr;
    const string& smaller = (lSize < rSize) ? lStr : rStr;
    int sIdx = 0, bIdx = 0, mistakes = 0;
    while (sIdx < smaller.size() && mistakes < 2) {
      if (bigger[bIdx] != smaller[sIdx]) {
        ++mistakes;
        ++bIdx;
      }
      else {
        ++bIdx;
        ++sIdx;
      }
    }
    if (sIdx == smaller.size() && mistakes < 2)
      return true;
  }
  return false;
}

int main() {
  cout << areSimilar("", "") << endl;
  cout << areSimilar("abcd", "abcd") << endl;
  cout << areSimilar("bcd", "abcd") << endl;
  cout << areSimilar("abcd", "acd") << endl;
  cout << areSimilar("abc", "abcd") << endl;
  cout << areSimilar("fbcd", "abcd") << endl;
  cout << areSimilar("abcd", "abcq") << endl;
  cout << areSimilar("a", "b") << endl;
  cout << areSimilar("accd", "abbdfd") << endl;
  cout << areSimilar("abcd", "zbcq") << endl;
  cout << areSimilar("accdababab", "abbdfd") << endl;
  system("pause");
  return 0;
}
