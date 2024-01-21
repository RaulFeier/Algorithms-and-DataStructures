#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 binary_exp(i64 a, i64 b) {
  if (b == 0) {
    return 1;
  }

  if (b == 1) {
    return a;
  }

  if (b % 2 == 1) {
    i64 ans = binary_exp(a, b / 2);
    return ans * ans * a;
  } else {
    i64 ans = binary_exp(a, b / 2);
    return ans * ans;
  }
}

int main() {
  cout << binary_exp(2, 40) << endl; 

  return 0;
}
