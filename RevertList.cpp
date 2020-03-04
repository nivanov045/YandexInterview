// Task: revert list with ints
struct node {
  node (node* iNext, int iData) : next(iNext), data(iData) {}
  node* next;
  int data;
};

node* revert(node* iHead) {
  if (iHead == nullptr || iHead->next == nullptr)
    return iHead;
  node* first = iHead;
  node* second = iHead->next;
  node* third = second->next;
  while (third != nullptr) {
    second->next = first;
    first = second;
    second = third;
    third = third->next;
  }
  iHead->next = nullptr;
  second->next = first;
  return second;
}

int main() {
  node* test0Node = nullptr;
  test0Node = revert(test0Node);
  node* test1Node = new node(nullptr, 0);
  test1Node = revert(test1Node);
  node* test2second = new node(nullptr, 1);
  node* test2first = new node(test2second, 0);
  test2first = revert(test2first);
  node* test3third = new node(nullptr, 2);
  node* test3second = new node(test3third, 1);
  node* test3first = new node(test3second, 0);
  test3first = revert(test3first);
  node* test4fives = new node(nullptr, 4);
  node* test4forth = new node(test4fives, 3);
  node* test4third = new node(test4forth, 2);
  node* test4second = new node(test4third, 1);
  node* test4first = new node(test4second, 0);
  test4first = revert(test4first);
  return 0;
}