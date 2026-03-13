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

int lucas(int n, int k) {
  if (n == k)
    return 1;

  int ni = n % MOD;
  int ki = k % MOD;

  return 1ll * comb(ni, ki) * lucas(n / MOD, k / MOD) % MOD;
} // if MOD smaller then N and MOD prime

int Catalan(int n) {
  return 1ll * bpow((n + 1), MOD - 2) * comb(2 * n, n) % MOD;
}
/*
http://www.geometer.org/mathcircles/catalan.pdf
Number of correct bracket sequence consisting of N opening and N closing
brackets.
The number of rooted full binary trees with N + 1 leaves (vertices are
not numbered). A rooted binary tree is full if every vertex has either two
children or no children.
The number of ways to completely parenthesize N + 1 factors.
The number of triangulations of a convex polygon with N + 2 sides (i.e. the
number of partitions of polygon into disjoint triangles by using the diagonals).
The number of ways to connect the 2N points on a circle to form N disjoint
chords.
*/

int Bell_numbers(int n) {
  // Bn = Sum from i=0 to n-1 (comb(n - 1, i) * Bi);
}
/*
Bell number is the sum from k=0 to N, Stirling_2[N][k]
 */

int main() {
  PreProces();

  return 0;
}
