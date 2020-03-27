// Task: count size of maximum subarray of '1' whith one change '1'->'0' or '0'->'1' at input array 
// (change must(!) be done, even if array ~ '11111': '11111'->'01111', answer 4)

#include <utility>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int countOnes(const vector<int>& iVec) {
  int result = 0;
  int leftIter, rightIter;
  for (int middleIter = 0; middleIter < iVec.size(); ++middleIter) {
    if (iVec[middleIter] != 0)
      continue;
    int curRes = 1;
    leftIter = middleIter - 1;
    rightIter = middleIter + 1;
    while (leftIter >= 0 && iVec[leftIter] == 1) {
      ++curRes;
      --leftIter;
    }
    while (rightIter < iVec.size() && iVec[rightIter] == 1) {
      ++curRes;
      ++rightIter;
    }
    result = max(result, curRes);
  }
  if (result == 0)
    result = max(int(iVec.size()) - 1, 0);
  return result;
}

int main() {
  vector<vector<int>> tests = {
    {},
    {0},
    {1},
    {1, 0},
    {1, 0, 0, 1, 0, 1, 0},
    {1, 0, 0, 1, 0, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
  };
  for (auto test : tests) {
    cout << countOnes(test) << endl;
  }
  return 0;
}