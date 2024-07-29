#include <bits/stdc++.h>

using namespace std;

bitset<10000010> bs;
vector<int> p;

void sieve(int N) {
  bs[0] = bs[1] = 0;

  for (int i = 2; i < N + 1; i++) {
    if (bs[i]) {
      for (int j = i * i; j < N + 1; j += i) {
        bs[j] = 0;
      }
      p.push_back(i);
    }
  }
}

bool isPrime(int N) {
  if (N < bs.size()) {
    return bs[N];
  }

  for (int i = 0; i < p.size() and p[i] * p[i] <= N; i++) {
    if (N % p[i] == 0) {
      return false;
    }
  }

  return true;
}

vector<int> factors(int N) {
  vector<int> fact;

  for (int i = 0; i < p.size() and p[i] * p[i] <= N; i++) {
    while (N % p[i] == 0) {
      fact.push_back(p[i]);
      N /= p[i];
    }
  }

  if (N != 1) {
    fact.push_back(N); // n can be prime
  }

  return fact;
}

int numPrimeFactors(int N) {
  int ans = 0;

  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
    while (N % p[i] == 0) {
      N /= p[i];
      ++ans;
    }

  return ans + (N != 1);
}

int numDiffPF(int N) {
  int ans = 0;

  for (int i = 0; i < p.size() && p[i] * p[i] <= N; ++i) {
    if (N % p[i] == 0)
      ++ans; // count this prime factor
    while (N % p[i] == 0)
      N /= p[i]; // only once
  }
  if (N != 1)
    ++ans;

  return ans;
}

int numDiv(int N) {
  int ans = 1; // start from ans = 1

  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
    int power = 0; // count the power
    while (N % p[i] == 0) {
      N /= p[i];
      ++power;
    }
    ans *= power + 1; // follow the formula
  }

  return (N != 1) ? 2 * ans : ans; // last factor = N^1
}

int sumDiv(int N) {
  int ans = 1; // start from ans = 1

  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
    int multiplier = p[i], total = 1;
    while (N % p[i] == 0) {
      N /= p[i];
      total += multiplier;
      multiplier *= p[i];
    } // total for
    ans *= total; // this prime factor
  }
  if (N != 1)
    ans *= (N + 1); // N^2-1/N-1 = N+1

  return ans;
}

int EulerPhi(int N) {
  int ans = N; // start from ans = N

  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
    if (N % p[i] == 0)
      ans -= ans / p[i]; // count unique
    while (N % p[i] == 0)
      N /= p[i]; // prime factor
  }

  if (N != 1)
    ans -= ans / N; // last factor

  return ans;
}
