// Task: calculate sum of two hexadecimal numbers defined by a pair of strings
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int charToInt (char c) {
  if (static_cast<int>('0') <= static_cast<int>(c) && static_cast<int>(c) <= static_cast<int>('9'))
    return static_cast<int>(c) - static_cast<int>('0');
  return static_cast<int>(c) - static_cast<int>('A') + 10;
}

char intToChar(int n) {
  if (0 <= n && n <= 9)
    return static_cast<char>(static_cast<int>('0') + n);
  return static_cast<char>(static_cast<int>('A') + n - 10);
}

std::string sum(const std::string& iLeft, const std::string& iRight)
{
  std::string result;
  int it = 0, leftLast = iLeft.size() - 1, rightLast = iRight.size() - 1, additional = 0;
  while (leftLast - it >= 0 || rightLast - it >= 0) {
    int left = leftLast - it >= 0 ? charToInt(iLeft[leftLast - it]) : 0;
    int right = rightLast - it >= 0 ? charToInt(iRight[rightLast - it]) : 0;
    auto sum = left + right + additional;
    result.push_back(intToChar(sum % 16));
    if (sum > 15)
      additional = 1;
    else
      additional = 0;
    ++it;
  }
  if (additional)
    result.push_back(intToChar(1));
  std::reverse(result.begin(), result.end());
  return result;
}

bool test(const std::string& iLeft, const std::string& iRight, const std::string& iResult)
{
  return sum(iLeft, iRight).compare(iResult) == 0;
}

int main(int argc, char* argv[])
{
  for (int i = 0; i <= 15; ++i)
    std::cout << intToChar(i) << ' ';
  std::cout << std::endl;
  for (auto c :{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' })
    std::cout << charToInt(c) << ' ';
  std::cout << std::endl;
  std::cout << sum("AFE45", "FFFF6");
  return 0;
}
