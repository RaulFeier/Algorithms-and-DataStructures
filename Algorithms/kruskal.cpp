#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
  vector<int> p, rank;

public:
  UnionFind(int n) {
    p.assign(n, 0);
    iota(p.begin(), p.end(), 0);
    rank.assign(n, 0);
  }

  int findSet(int i) {
    int t = i;
    while (p[i] != i) {
      i = p[i];
    }
    if (t != i) {
      p[t] = i;
    }
    return i;
  }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (isSameSet(i, j))
      return;
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y])
      ++rank[y];
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> mst(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    mst[i] = {w, u, v};
  }

  sort(mst.begin(), mst.end()); // sort by weight, tuple has builtin comparation
                                // func, O(N log N)

  int mnt_cost, num_taken = 0;

  UnionFind UF(n);

  for (auto &[w, u, v] : mst) {
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
