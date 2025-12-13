// // https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> adj(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  vector<int> d(N + 1, INF), par(N + 1, -1);
  q.push(1);
  d[1] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (d[u] + 1 < d[v]) {
        d[v] = d[u] + 1;
        par[v] = u;
        q.push(v);
      }
    }
  }

  if (d[N] == INF) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }

  // print the path
  cout << d[N] + 1 << '\n';
  int cur = N;
  vector<int> path;

  while (cur != -1) {
    path.push_back(cur);
    cur = par[cur];
  }

  reverse(path.begin(), path.end());
  for (auto u : path) {
    cout << u << ' ';
  }
  cout << '\n';

  return 0;
}