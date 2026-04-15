#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cout << __builtin_popcount(31) << '\n';   // the number of 1s in the binary
  cout << __builtin_popcountll(31) << '\n'; // long long version

  cout << __builtin_clz(42) << '\n'; // the leading number of zeros

  cout << __builtin_ctz(42) << '\n'; // the trailing number of zeros

  bitset<100> bs;

  cout << bs.count() << '\n'; // count the number of set bits

  cout << bs._Find_first() << '\n'; // return the first 1st bit set

  cout << bs._Find_next(3)
       << '\n'; // return the first bit set after index, here index =3

  return 0;
}
