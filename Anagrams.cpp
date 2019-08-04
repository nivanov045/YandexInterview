#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  std::string firstWord, secondWord;
  in >> firstWord;
  if (firstWord.empty()) {
    out << 1;
    return 0;
  }
  in >> secondWord;

  std::map<char, size_t> letters;
  for (size_t idx = 0; idx < firstWord.size(); ++idx)
    ++letters[firstWord[idx]];
  for (size_t idx = 0; idx < secondWord.size(); ++idx) {
    if (!letters.count(secondWord[idx])) {
      out << 0;
      return 0;
    }
    if (letters[secondWord[idx]] == 1)
      letters.erase(secondWord[idx]);
    else
      --letters[secondWord[idx]];
  }
  out << letters.empty() ? 1 : 0;
  return 0;
}