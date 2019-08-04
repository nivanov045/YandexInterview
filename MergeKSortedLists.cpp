#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  size_t numOfEls;
  in >> numOfEls;
  std::map<size_t, size_t> result;
  size_t curNum = 0;
  for (size_t idx = 0; idx < numOfEls; ++idx) {
    size_t numOfElsInArray = 0;
    in >> numOfElsInArray;
    for (size_t idxInner = 0; idxInner < numOfElsInArray; ++idxInner) {
      in >> curNum;
      ++result[curNum];
    }
  }
  for (auto el : result)
    for (size_t idx = 0; idx < el.second; ++idx)
      out << el.first << ' ';
  return 0;
}