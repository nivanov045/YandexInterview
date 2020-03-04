// Print all primes between 2 to n
#include <vector>
#include <iostream>

void GetPrimes(int n) {
  std::vector<int> result;
  for (int i = 2; i <= n; ++i) {
    bool isPrime = true;
    for (auto num : result) {
      if (i % num == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      result.push_back(i);
      std::cout << i << ' ';
    }
  }
}

int  main() {
  GetPrimes(0);
  std::cout << std::endl;
  GetPrimes(1);
  std::cout << std::endl;
  GetPrimes(2);
  std::cout << std::endl;
  GetPrimes(100);
  std::cout << std::endl;
  GetPrimes(10000);
  std::cout << std::endl;
  return 0;
}