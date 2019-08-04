#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  struct node {
    node* leftNode;
    node* rightNode;
    std::string bracket;
    int sumInNode;
    size_t openBracketsInNode;
  };

  size_t numOfEls;
  in >> numOfEls;
  if (numOfEls == 0)
    return 0;
  
  size_t depth = 1;
  std::vector<node*> leafs;
  leafs.push_back(new node({ nullptr, nullptr, "(", 1, 1 }));
  while (depth < numOfEls * 2) {
    std::vector<node*> newLeafs;
    for (auto l : leafs) {
      if (l->openBracketsInNode < numOfEls) {
        node* newLeftNode = new node({ nullptr, nullptr, l->bracket + '(', l->sumInNode + 1,
                                       l->openBracketsInNode + 1 });
        l->leftNode = newLeftNode;
        newLeafs.push_back(newLeftNode);
      }
      if (l->sumInNode > 0) {
        node* newRightNode = new node({ nullptr, nullptr, l->bracket + ')', l->sumInNode - 1,
                                        l->openBracketsInNode });
        l->rightNode = newRightNode;
        newLeafs.push_back(newRightNode);
      }
    }
    for (auto l : leafs)
      delete(l);
    leafs = move(newLeafs);
    ++depth;
  }
  for (auto l : leafs)
    out << l->bracket << '\n';
  return 0;
}