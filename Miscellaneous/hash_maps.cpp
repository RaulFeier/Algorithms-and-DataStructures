#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

struct clash {
  const uint64_t C = (long long)(4e18 * acos(0)) + 71; // large odd number
  const int RANDOM = chrono::steady_clock::now().time_since_epoch().count();
  long long operator()(long long x) const {
    return __builtin_bswap64((x ^ RANDOM) * C);
  }
};

template <typename K, typename V> using hmap = gp_hash_table<K, V, clash>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // try this but sometimes its faster
  // null_type its just to be a std::unordered_set
  hmap<int, null_type> h({}, {}, {}, {}, {1 << 16});

  hmap<int, int> h2;

  // this hash_map should be much faster then std::unordered_map and unhackable

  return 0;
}
