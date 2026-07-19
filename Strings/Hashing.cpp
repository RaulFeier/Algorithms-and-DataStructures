#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

class Hashing {
public:
  const i64 MOD = 1e9 + 9;
  const i64 B = uniform_int_distribution<i64>(0, MOD - 1)(rng);

  vector<i64> pow, hash;

  Hashing(string &s) {
    pow.resize(s.size() + 1);
    pow[0] = 1;

    for (int i = 1; i < (int)pow.size() - 1; i++) {
      pow[i] = (pow[i - 1] * B) % MOD;
    }

    hash.resize(s.size() + 1);
    for (int i = 1; i < (int)hash.size(); i++) {
      hash[i] = (hash[i - 1] * B + s[i - 1]) % MOD;
    }
  }

  inline i64 get_hash(int l, int r) {
    i64 h = hash[r + 1] - (pow[r - l + 1] * hash[l] % MOD) % MOD;
    return h < 0 ? h + MOD : h;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;

  Hashing H(s);

  int n = s.size();

  for (int i = 0; i < n; i++) {
    int curidx = 0;
    bool ok = true;

    while (curidx < n && ok) {
      int len = min(i + 1, n - curidx);
      ok &= H.get_hash(0, len - 1) == H.get_hash(curidx, curidx + len - 1);
      curidx += len;
    }

    if (ok) {
      cout << i + 1 << " ";
    }
  }
  cout << '\n';

  return 0;
}
