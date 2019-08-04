#include <fstream>
#include <algorithm>

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");
  
  size_t numOfEls;
  in >> numOfEls;

  size_t maxSize = 0;
  size_t curSize = 0;
  bool inside = false;
  for (size_t idx = 0; idx < numOfEls; ++idx) {
    int x;
    in >> x;
    if (inside) {
      if (x == 0) {
        inside = false;
        maxSize = std::max(maxSize, curSize);
        curSize = 0;
      }
      else {
        ++curSize;
      }
    }
    else {
      if (x == 0) {
        continue;
      }
      else {
        inside = true;
        ++curSize;
      }
    }
  }
  maxSize = std::max(maxSize, curSize);
  out << maxSize;
  return 0;
}