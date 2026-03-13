// https://codeforces.com/contest/840/problem/D
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Query {
  int l, r, k, index;
};

int freq[300005], a[300005];

int get_answer(int l, int r, int condition) {
  int mn = 1e9;
  uniform_int_distribution<int> number(l, r);

  for (int i = 0; i < 80; i++) {
    int index = number(rng);

    if (freq[a[index]] > condition)
      mn = min(mn, a[index]);
  }

  if (mn != 1e9)
    return mn;

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, Q;
  cin >> N >> Q;

  for (int i = 0; i < N; i++)
    cin >> a[i];

  vector<Query> queries(Q);

  for (int i = 0; i < Q; i++) {
    cin >> queries[i].l >> queries[i].r >> queries[i].k;
    queries[i].l--, queries[i].r--;
    queries[i].index = i;
  }

  int block = sqrt(N); // you can take block a fixed size like 350 or something
                       // depends on problem and its faster
  sort(queries.begin(), queries.end(), [&](Query a, Query b) -> bool {
    int L1 = a.l / block;
    int L2 = b.l / block;
    if (L1 == L2)
      return a.r < b.r;

    return L1 < L2;
  });

  vector<int> res(Q);
  int L = 0, R = -1;

  for (int i = 0; i < Q; i++) {
    int l = queries[i].l;
    int r = queries[i].r;

    while (R < r) {
      freq[a[++R]]++;
    }

    while (R > r) {
      freq[a[R--]]--;
    }

    while (L < l) {
      freq[a[L++]]--;
    }

    while (L > l) {
      freq[a[--L]]++;
    }

    res[queries[i].index] = get_answer(l, r, (r - l + 1) / queries[i].k);
  }

  for (auto c : res)
    cout << c << '\n';

  return 0;
}
