// https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
vector<int> ord;

void dfs(int u) {
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
  ord.push_back(u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  for (int i = 1; i <= N; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  reverse(ord.begin(), ord.end());

  // check is feasible
  vector<int> pos(N + 1);
  for (int i = 0; i < (int)ord.size(); i++) {
    pos[ord[i]] = i;
  }

  for (int u = 1; u <= N; u++) {
    for (auto v : g[u]) {
      if (pos[u] >= pos[v]) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
  }

  for (auto u : ord)
    cout << u << ' ';
  cout << '\n';

  return 0;
}
