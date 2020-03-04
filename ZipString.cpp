// "" -> ""
// aaaaaa -> 6a
// aaabbfdaa -> 3a2bfd2a

#include <iostream>
#include <map>
#include <string>

int main(int argc, char* argv[])
{
  char curChar, stepChar;
  while (std::cin >> curChar) {
    int counter = 1;
    while (std::cin >> stepChar && stepChar == curChar) {
      ++counter;
    }
    std::cout << counter << curChar;
  }
  return 0;
}
