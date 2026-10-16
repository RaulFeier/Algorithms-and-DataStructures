#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const i64 MOD = 1e9 + 7; // or (1LL << 61) - 1 or 999999999999989
const i64 B = uniform_int_distribution<i64>(31, MOD - 1)(rng);

class Hashing {
private:
  __int128 mul(i64 a, i64 b) { return (__int128)a * b; }
  i64 mod_mul(i64 a, i64 b) { return mul(a, b) % MOD; }

public:
  vector<i64> pow, hash;

  Hashing(vector<int> &v) { // or a string idk
    pow.resize(v.size() + 1);
    hash.resize(v.size() + 1);

    pow[0] = 1;
    for (int i = 1; i <= v.size(); i++)
      pow[i] = mod_mul(pow[i - 1], B);

    for (int i = 1; i <= v.size(); i++) {
      hash[i] = (mod_mul(hash[i - 1], B) + v[i - 1] + MOD) % MOD;
    }
  }

  // l and r are from 0 to N - 1 where N is the size of the vector(string)
  i64 get_hash(int l, int r) {
    i64 h = (hash[r + 1] - mod_mul(pow[r - l + 1], hash[l]) + MOD) % MOD;
    return (h > 0 ? h : h + MOD);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
