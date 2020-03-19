// Task: replace spaces in given string by '%20'

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void replaceSpaces (string& iStr) {
  int numOfSpaces = 0;
  for (int i = 0; i < iStr.size(); ++i)
    if (iStr[i] == ' ')
      ++numOfSpaces;
  auto idxLast = iStr.size() - 1;
  iStr.resize(iStr.size() + numOfSpaces * 2);
  auto newIdxLast = iStr.size() - 1;
  while (idxLast >= 0 && idxLast != newIdxLast)
  {
    if (iStr[idxLast] == ' ') {
      iStr[newIdxLast] = '0';
      iStr[newIdxLast - 1] = '2';
      iStr[newIdxLast - 2] = '%';
      newIdxLast -= 2;
    }
    else {
      iStr[newIdxLast] = iStr[idxLast];
    }
    --idxLast;
    --newIdxLast;
  }
}

int main() {
  vector<string> tests = { "", " ", " abc", "abc ", " abc ", " abc dfs ", " abc  dfs ", " abc dfs a", " abc dfs a   " };
  for (auto test : tests) {
    cout << test << ": ";
    replaceSpaces(test);
    cout << test << endl;
  }
  system("pause");
  return 0;
}
