#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

string summaryRanges(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  string result;
  if (nums.empty())
    return result;
  int itFirst = 0, itLast = 0;
  int first = nums[itFirst], last = nums[itLast];
  while (itFirst < nums.size()) {
    while (itLast < nums.size() && (itLast == itFirst || nums[itLast - 1] + 1 == nums[itLast]))
      ++itLast;
    stringstream s;
    s << nums[itFirst];
    if (itFirst != itLast - 1)
      s << "->" << nums[itLast - 1];
    if (itLast != nums.size())
      s << ',';
    result.append(s.str());
    itFirst = itLast;
  }
  return result;
}

int main() {
  vector<int> v({ 0,1,2,4,5,7 });
  cout << summaryRanges(v) << endl;
  v = { 0 };
  cout << summaryRanges(v) << endl;
  v = { 0,1,2,3 };
  cout << summaryRanges(v) << endl;
  v = { 0, 4,5,6 };
  cout << summaryRanges(v) << endl;
  system("pause");
}
