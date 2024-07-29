#include "../../../HEADER.h"

inline i64 mod(i64 n) {
  // if n cannot be negative for significant speed gain replace this with
  return n < MOD ? n : n % MOD;

  // if n is negetive use this
  // return ((n % MOD) + MOD) % MOD; // MOD here is 1e9 + 7;
}

int fact[200000];

void PreProces() {
  fact[0] = 1;

  for (int i = 1; i <= 200000; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}

i64 bpow(i64 a, i64 b) {
  if (b == 0)
    return 1;
  if (b & 1) {
    return a * bpow(a, b - 1) % MOD;
  }

  i64 aux = bpow(a, b >> 1);
  return aux * aux % MOD;
}

i64 ifact(i64 n) { return bpow(n, MOD - 2); }

i64 arn(i64 n, i64 k) {
  if (n < k)
    return 0;

  return fact[n] * ifact(fact[n - k]) % MOD;
}

i64 comb(i64 n, i64 k) {
  if (n < k)
    return 0;
  if (k == 0 or n == k)
    return 1;

  return (fact[n] * ifact(fact[n - k])) % MOD * ifact(fact[k]) % MOD;
}

int main() {
  PreProces();
  cout << comb(10, 3) << endl;

  return 0;
}
