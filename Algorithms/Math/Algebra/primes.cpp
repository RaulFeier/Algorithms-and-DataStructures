#include <bits/stdc++.h>

using namespace std;

vector<bool> bs;
vector<int> p;

void steve(int n) {
  bs.resize(n + 1, true);

  bs[0] = bs[1] = false;

  for (int i = 2; i < n + 1; i++) {
    if (bs[i]) {
      for (int j = i * i; j < n + 1; j += i) {
        bs[j] = false;
      }
      p.push_back(i);
    }
  }
}

bool isPrime(int n) {
  if (n < bs.size()) {
    return bs[n];
  }

  for (int i = 0; i < p.size() and p[i] * p[i] <= n; i++) {
    if (n % p[i] == 0) {
      return false;
    }
  }

  return true;
}

vector<int> factors(int n) {
  vector<int> fact;

  for (int i = 0; i < p.size() and p[i] * p[i] <= n; i++) {
    while (n % p[i] == 0) {
      fact.push_back(p[i]);
      n /= p[i];
    }
  }

  if (n != 1) {
    fact.push_back(n); // n can be prime
  }

  return fact;
}

int main() { return 0; }