// Task: is exist vertical axis of symmetry, which devided array of 2D-points

#include <utility>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
  Point(int iX, int iY) : x(iX), y(iY) {}
  int x;
  int y;
};

bool isExist(const std::vector<Point>& iPoints) {
  //find min, max by x -> get possible axis coord
  //check for all points existing of symmetry point
}

int main() {
  vector<vector<Point>> tests = {
    {},
    {{0, 10}},
    {{1, 24}},
    {{13, 43}, {13, 44}},
    {{13, 43}, {13, 45}},
    {{13, 43}, {13, 45}},
    {{12, 43}, {13, 45}},
    {{0, 1}, {0, 2}},
    {{0, -4}, {0, 8}},
    {{-1, 2}, {8, 3}, {5, 2}, {-4, 3}},
    {{-1, 2}, {8, 3}, {5, 2}, {-5, 3}},
    {{-1, 2}, {8, 3}, {5, 2}, {-4, 1}},
  };
  for (auto test : tests) {
    cout << isExist(test) << endl;
  }
  return 0;
}