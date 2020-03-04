//Task: remove zeros from std::vector with complexity O(n)

#include <vector>
#include <iostream>

void removeZeros(std::vector<int>& ioVec) {
  int nonZeroIdx = 0, currentIdx = 0;
  while (currentIdx < ioVec.size()) {
    if (ioVec[currentIdx] != 0) {
      ioVec[nonZeroIdx] = ioVec[currentIdx];
      nonZeroIdx++;
    }
    currentIdx++;
  }
  ioVec.erase(ioVec.begin() + nonZeroIdx, ioVec.end());
}

void print(const std::vector<int>& iVec) {
  for (auto v : iVec) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> testEmpty;
  print(testEmpty);
  removeZeros(testEmpty);
  print(testEmpty);
  std::vector<int> testZerosOnly(2, 0);
  print(testZerosOnly);
  removeZeros(testZerosOnly);
  print(testZerosOnly);
  std::vector<int> testNonZerosOnly(2, 1);
  print(testNonZerosOnly);
  removeZeros(testNonZerosOnly);
  print(testNonZerosOnly);
  std::vector<int> mixed = { 0, 0, 1, 2,3, 0, 4, 0, 0 };
  print(mixed);
  removeZeros(mixed);
  print(mixed);
}