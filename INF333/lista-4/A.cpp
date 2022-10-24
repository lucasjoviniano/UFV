#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int BITSET_SIZE = 100000;
const int LARGEST_DIFFERENCE = 1000001;

int main() {
  bitset<BITSET_SIZE> isPrime;
  bitset<LARGEST_DIFFERENCE> isComposite;
  vector<int> primes;
  isPrime.set();
  isPrime.reset(0);
  isPrime.reset(1);

  for (int n = 2; n < BITSET_SIZE; ++n) {
    if (isPrime[n]) {
      if ((unsigned long long)n * n < BITSET_SIZE) {
        for (int m = n * n; m < BITSET_SIZE; m += n)
          isPrime.reset(m);
      }
      primes.push_back(n);
    }
  }

  int l, u;
  while (cin >> l >> u) {
    isComposite.reset();
    for (int i = 0; i < primes.size() && (long long)primes[i] * primes[i] <= u;
         i++) {
      const int &prime = primes[i];
      long long start = l % prime == 0 ? l : (long long)l + (prime - l % prime);
      for (long long n = start; n <= u; n += prime) {
        if (n != prime)
          isComposite.set(n - l);
      }
    }
    if (l == 1)
      isComposite.set(0);

    long long clb = 0, cle = u, dib = 0, die = 0;
    long long lastPrime = 0;
    for (long long n = l; n <= u; n++) {
      if (!isComposite[n - l]) {
        if (lastPrime != 0) {
          if (n - lastPrime < cle - clb) {
            clb = lastPrime;
            cle = n;
          }
          if (n - lastPrime > die - dib) {
            dib = lastPrime;
            die = n;
          }
        }
        lastPrime = n;
      }
    }
    if (clb == 0)
      cout << "There are no adjacent primes." << endl;
    else
      cout << clb << "," << cle << " are closest, " << dib << "," << die
           << " are most distant." << endl;
  }
  return 0;
}
