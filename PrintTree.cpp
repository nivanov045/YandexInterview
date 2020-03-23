// Task: print binary tree by depth level with line break between levels
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct Node
{
  Node(Node* iLeft, Node* iRight, char iData) : left(iLeft), right(iRight), data(iData) {}
  Node(char iData) : left(nullptr), right(nullptr), data(iData) {}
  Node* left;
  Node* right;
  char data;
};

void printTree(const Node* iRoot) {
  if (iRoot == nullptr)
    return;
  queue<const Node*> database;
  database.push(iRoot);
  database.push(nullptr);
  while (!(database.front() == nullptr && database.size() == 1))
  {
    const Node* curNode = database.front();
    database.pop();
    if (curNode == nullptr) {
      database.push(nullptr);
      cout << endl;
      continue;
    }
    cout << curNode->data;
    if (curNode->left != nullptr)
      database.push(curNode->left);
    if (curNode->right != nullptr)
      database.push(curNode->right);
  }
}

int main() {
  Node* F;

  vector<Node*> tests = {
    nullptr,
    new Node(nullptr, nullptr, 'A'),
    new Node(new Node('B'), new Node('C'), 'A'),
    new Node(new Node(new Node('D'), new Node(nullptr, new Node('F'), 'E'), 'B'),
      new Node(new Node('G'), nullptr, 'C'), 'A')
  };
  for (auto test : tests) {
    printTree(test);
    cout << endl;
  }
  system("pause");
  return 0;
}