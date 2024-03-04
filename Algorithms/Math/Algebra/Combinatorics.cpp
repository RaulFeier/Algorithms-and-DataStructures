#include "../../../HEADER.h"

inline i64 mod(i64 n) {
  // if n cannot be negative for significant speed gain replace this with
  return n < MOD ? n : n % MOD;

  // if n is negetive use this
  // return ((n % MOD) + MOD) % MOD; // MOD here is 1e9 + 7;
}

inline i64 mult(i64 x, i64 y) { return (x * y) % MOD; }

hmap<i64, i64> dp;

i64 fact(i64 n) {
  if (n == 0 or n == 1)
    return 1;

  auto f = dp.find(n);
  if (f != dp.end()) {
    return f->second;
  }

  return dp[n] = mod(mod(n) * fact(n - 1));
}

i64 bpow(i64 a, i64 b) {
  if (b == 0)
    return 1;
  if (b == 1)
    return mod(a);
  if (b % 2 == 0) {
    i64 ans = bpow(a, b / 2);
    return mult(ans, ans);
  } else {
    return mult(bpow(a, b - 1), mod(a));
  }
}

i64 ifact(i64 n) {
  i64 x = fact(n);
  return bpow(x, MOD - 2);
}

i64 arn(i64 n, i64 k) {
  if (n < k)
    return 0;

  return mult(fact(n), ifact(n - k));
}

i64 comb(i64 n, i64 k) {
  if (n < k)
    return 0;
  if (k == 0 or n == k)
    return 1;
  if (n == 1)
    return mod(n);
  return mult(mult(fact(n), ifact(n - k)), ifact(k));
}

int main() {
  cout << comb(10, 3) << endl;

  return 0;
}