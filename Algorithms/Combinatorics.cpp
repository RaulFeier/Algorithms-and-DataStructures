#include <bits/stdc++.h>

using namespace std;

const int maxN = 200000;
const int MOD = 1e9 + 7; // should be prime number

int fact[maxN + 2];
int ifact[maxN + 2];

int bpow(int a, int b) {
  if (b == 0)
    return 1;
  if (b & 1)
    return (1ll * a * bpow(a, b - 1)) % MOD;

  int aux = bpow(a, b / 2);
  return (1ll * aux * aux) % MOD;
}

void PreProces() {
  fact[0] = 1;

  for (int i = 1; i <= maxN; i++) {
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }

  ifact[maxN] = bpow(fact[maxN], MOD - 2);
  for (int i = maxN - 1; i >= 0; i--) {
    ifact[i] = (1ll * ifact[i + 1] * (i + 1)) % MOD;
  }
}

int comb(int n, int k) {
  return (1ll * fact[n] * ifact[n - k]) % MOD * ifact[k] % MOD;
}

int main() {
  PreProces();

  return 0;
}