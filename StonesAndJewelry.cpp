#include <fstream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[])
{
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");
  
  std::string jew, stones;
  in >> jew >> stones;

  std::sort(jew.begin(), jew.end());
  jew.erase((std::unique(jew.begin(), jew.end())), jew.end());
  out << std::count_if(stones.begin(), stones.end(), [&jew](char in) { return jew.find(in) != std::string::npos; });
  out.close();
  return 0;
}
