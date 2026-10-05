// https://codeforces.com/edu/course/2/lesson/7/3/practice/contest/289392/problem/A
#include <bits/stdc++.h>

using namespace std;

class DSU {
private:
  vector<int> p, rank, setSize;
  int connected_components;

  struct Change {
    int child;
    int parent;
    int old_size;
  };

  vector<Change> history;

public:
  DSU(int N) { // from 1..N
    p.resize(N + 1);
    iota(p.begin(), p.end(), 0);
    rank.assign(N + 1, 1);
    setSize.assign(N + 1, 1);
    connected_components = N;
    history.reserve(N + 1);
  }

  int find(int i) {
    while (i != p[i])
      i = p[i];

    return i;
  }

  bool unite(int a, int b) {
    int x = find(a);
    int y = find(b);

    if (x == y)
      return false;

    if (rank[x] > rank[y]) {
      history.push_back({y, x, rank[x]});
      p[y] = x;
      rank[x] += rank[y];
    } else {
      history.push_back({x, y, rank[y]});
      p[x] = y;
      rank[y] += rank[x];
    }

    connected_components--;
    return true;
  }

  void rollback() {
    auto b = history.back();
    history.pop_back();

    p[b.child] = b.child;
    rank[b.parent] = b.old_size;
    connected_components++;
  }

  void rollback_to_checkpoint(int checkpoint) {
    while ((int)history.size() > checkpoint)
      rollback();
  }

  int snapshot() { return (int)history.size(); }
  int Connected_components() { return connected_components; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  DSU uf(N);

  vector<int> checkpoints;
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;

    if (s == "persist") {
      checkpoints.push_back(uf.snapshot());
    } else if (s == "union") {
      int u, v;
      cin >> u >> v;

      uf.unite(u, v);
      cout << uf.Connected_components() << '\n';
    } else {
      uf.rollback_to_checkpoint(checkpoints.back());
      checkpoints.pop_back();
      cout << uf.Connected_components() << '\n';
    }
  }

  return 0;
}
