// https://cses.fi/problemset/task/1691
#include <bits/stdc++.h>

using namespace std;

vector<bool> used;
vector<int> order;

void dfs(int node, vector<vector<pair<int, int>>> &adj) {
  while (!adj[node].empty()) {
    auto c = adj[node].back();
    adj[node].pop_back();

    if (used[c.second])
      continue;

    used[c.second] = 1;
    dfs(c.first, adj);
  }

  order.push_back(node);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<pair<int, int>>> adj(N + 1);
  vector<int> degree(N + 1, 0);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    degree[u]++;
    degree[v]++;
  }

  used.assign(M + 1, 0);

  for (int i = 1; i <= N; i++) {
    if (degree[i] & 1) {
      cout << "IMPOSSIBLE" << '\n';
      return 0;
    }
  }

  dfs(1, adj);

  if (order.size() != M + 1) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }

  for (auto &c : order)
    cout << c << " ";
  cout << '\n';

  return 0;
}