#include "../../../../HEADER.h"

class UnionFind {
private:
  vi64 p, rank;

public:
  UnionFind(i64 n) {
    p.assign(n, 0);
    for (i64 i = 0; i < n; i++)
      p[i] = i;
    rank.assign(n, 0);
  }

  i64 findSet(i64 i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (isSameSet(i, j))
      return;
    i64 x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y])
      ++rank[y];
  }
};

int main() {
  i64 n, m;
  cin >> n >> m;

  vector<tuple<i64, i64, i64>> mst(n);
  for (i64 i = 0; i < m; i++) {
    i64 w, u, v;
    cin >> w >> u >> v;

    mst[i] = {w, u, v};
  }

  sort(mst.begin(), mst.end()); // sort by weight, tuple has builtin comparation
                                // func, O(N log N)

  i64 mnt_cost, num_taken = 0;

  UnionFind UF(n);

  for (let & [ w, u, v ] : mst) {
    if (UF.isSameSet(u, v))
      continue;
    mnt_cost += w;
    UF.unionSet(u, v);
    ++num_taken;
    if (num_taken == n - 1)
      break; // optimization
  }

  cout << mnt_cost << endl;

  return 0;
}
