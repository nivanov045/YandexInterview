#include <fstream>
#include <algorithm>
#include <set>

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  size_t numOfEls;
  in >> numOfEls;

  if (numOfEls == 0)
    return 0;
  int lastNum;
  in >> lastNum;
  out << lastNum << '\n';
  for (size_t idx = 1; idx < numOfEls; ++idx) {
    int x;
    in >> x;
    if (x != lastNum) {
      out << x << '\n';
      lastNum = x;
    }
  }
  
  return 0;
}
