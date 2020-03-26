// Task: find two subtrees with equal alphabet (using only 'A-Z')
#include <utility>
#include <unordered_map>
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

int makeNumByChar(char c) {
  return (1 << ((int)c - (int)'A'));
}

int addToDatabase(Node* iNode, unordered_map<int, Node*>& ioDatabase, pair<Node*, Node*>& oResult) {
  if (iNode == nullptr)
    return 0;
  auto left = addToDatabase(iNode->left, ioDatabase, oResult);
  if (oResult.first != nullptr)
    return 0;
  auto right = addToDatabase(iNode->right, ioDatabase, oResult);
  if (oResult.first != nullptr)
    return 0;
  auto res = left | makeNumByChar(iNode->data) | right;
  if (ioDatabase.count(res)) {
    oResult = { ioDatabase[res], iNode };
    return 0;
  }
  ioDatabase[res] = iNode;
  return res;
}

pair<Node*, Node*> findIdenticalSubtries(Node* iRoot) {
  pair<Node*, Node*> result = { nullptr, nullptr };
  unordered_map<int, Node*> db;
  addToDatabase(iRoot, db, result);
  return result;
}

int main() {
  vector<Node*> tests = {
    new Node(new Node('A'), nullptr, 'A'),
    nullptr,
    new Node(nullptr, nullptr, 'A'),
    new Node(new Node('B'), new Node('C'), 'A'),
    new Node(new Node(new Node('D'), new Node(nullptr, new Node('F'), 'E'), 'B'),
      new Node(new Node('G'), nullptr, 'C'), 'A'),
    new Node(new Node(new Node('B'), new Node('C'), 'A'), new Node(new Node('C'), new Node('A'), 'B'), 'Z'),
    new Node(
      new Node(
        new Node('M'),
        new Node('C'),
        'B'),
      new Node(
        new Node(
          new Node('B'),
          nullptr,
          'M'),
        nullptr,
        'C'),
      'A'),
  };
  for (auto test : tests) {
    auto res = findIdenticalSubtries(test);
    if (res.first != nullptr)
      cout << res.first->data << ' ' << res.second->data << std::endl;
  }
  return 0;
}