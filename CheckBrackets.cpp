// Task: check brackets in string
#include <string>
#include <stack>
#include <iostream>

bool CheckBrackets(const std::string& iStr) {
  std::stack<char> braces;
  bool isOk = true;
  for (auto ch : iStr) {
    if (ch == '(' || ch == '{' || ch == '[')
      braces.push(ch);
    else if ((ch == ')' || ch == '}' || ch == ']')) {
      if (!braces.empty() && ((ch == ')' && braces.top() == '(') || (ch == ']' && braces.top() == '[') ||
        (ch == '}' && braces.top() == '{')))
        braces.pop();
      else {
        isOk = false;
        break;
      }
    }
  }
  if (braces.empty() && isOk)
    return true;
  return false;
}

int main() {
  std::cout << CheckBrackets("");
  std::cout << CheckBrackets("(");
  std::cout << CheckBrackets("()");
  std::cout << CheckBrackets("({)");
  std::cout << CheckBrackets("({})");
  std::cout << CheckBrackets("({])");
  std::cout << CheckBrackets("({)}");
  std::cout << CheckBrackets("(){}[]");
  std::cout << CheckBrackets("(){}[]{");
  std::cout << CheckBrackets("(){}[])");
}