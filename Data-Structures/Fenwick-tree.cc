#include <bits/stdc++.h>

using namespace std;

int lsbl(int x) { return x & (-x); }

const int Max_N = 200002;
int ft[Max_N + 1];

void update(int i, int val) {
  int crt = i + 1; // add 1 index from 0

  while (crt < Max_N) {
    ft[crt] += val;
    crt += lsbl(crt);
  }
}

int sum(int from) {
  from += 1; // add 1 index from 0

  int sum = 0;
  while (from > 0) {
    sum += ft[from];
    from -= lsbl(from);
  }

  return sum;
}

int sum(int from, int to) { return sum(to) - sum(from); }
