// Task: Search for a substring in a string without regard to letter order

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int findSubstr(const string& iStr, const string& iSubstr) {
  int result = -1;
  map<char, int> database;
  for (auto c : iSubstr)
    ++database[c];
  int leftIdx = 0, rightIdx = 0;
  while (rightIdx < iStr.size())
  {
    --database[iStr[rightIdx]];
    if (database[iStr[rightIdx]] == 0)
      database.erase(iStr[rightIdx]);
    if (rightIdx - leftIdx >= iSubstr.size()) {
      ++database[iStr[leftIdx]];
      if (database[iStr[leftIdx]] == 0)
        database.erase(iStr[leftIdx]);
      ++leftIdx;
    }
    if (database.empty()) {
      result = leftIdx;
      break;
    }
    ++rightIdx;
  }
  return result;
}

int main() {
  vector<pair<string, string>> tests = {
    {"abcdef", "e"},
    {"", ""},
    {"abcdddef", "ddcb"},
    {"abcdddefg", "feg"},
    {"abcdddefg", "bca"},
    {"abcdddefg", "fgg"},
  };
  for (auto test : tests) {
    cout << test.first << ", " << test.second << ": " << findSubstr(test.first, test.second) << endl;
  }
  system("pause");
  return 0;
}
