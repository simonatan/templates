// source: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
// O(nloglogn) ~ O(n)

#include <iostream>
#include <vector>

std::vector<bool> sieve(int n) {
  std::vector<bool> prime(n, 1);
  prime[0] = prime[1] = 0;
  for(int i = 2; i * i <= n; i++) {
    if (!prime[i]) continue;
    for(int x = i * i; x <= n; x += i) {
      prime[i] = 0;
    }
  }
  return prime;
}
