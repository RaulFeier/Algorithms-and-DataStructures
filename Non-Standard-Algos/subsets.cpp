#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & (-S))

int main() {
  int N = 5;

  for (int i = 0; i < (1 << N); i++) {
    int mask = i;

    while (mask) {
      int two = LSOne(mask);
      int j = __builtin_ctz(two);
      // do whatever with the subset
      mask -= two;
    }
  }

  return 0;
}
