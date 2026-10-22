// https://cses.fi/problemset/task/3406
// Is a theoreme that states a natural number N can be write as sum of 3
// triangle numbers
// extra problem https://codeforces.com/gym/103150/problem/F
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

bool check(i64 n) {
  i64 x = (-1 + sqrt(1 + 8 * n)) / 2;
  return (x * (x + 1) / 2) == n;
}

void solve() {
  i64 x;
  cin >> x;

  if (check(x)) {
    cout << 1 << '\n';
    return;
  }

  for (i64 i = 1; i * (i + 1) / 2 <= x; i++) {
    if (check(x - i * (i + 1) / 2)) {
      cout << 2 << '\n';
      return;
    }
  }

  cout << 3 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
