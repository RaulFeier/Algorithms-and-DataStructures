// https://cses.fi/problemset/task/2143
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void dfs(int node, vi &v, vector<int> &used, const vector<vi> &adj) {
  used[node] = true;

  for (auto c : adj[node]) {
    if (!used[c])
      dfs(c, v, used, adj);
  }

  v.push_back(node);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;

  vector<vi> adj(N + 1);
  vector<vi> trans_adj(N + 1);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    trans_adj[v].push_back(u);
  }

  vi order, used(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    if (!used[i])
      dfs(i, order, used, adj);
  }

  vector<int> root(N + 1);
  used.assign(N + 1, 0);
  reverse(order.begin(), order.end());

  for (auto c : order) {
    if (used[c])
      continue;

    vector<int> component;
    dfs(c, component, used, trans_adj);
    int min_elem = *min_element(component.begin(), component.end());
    for (auto u : component)
      root[u] = min_elem;
  }

  vector<vi> condensation_graph(N + 1);
  for (int i = 1; i <= N; i++) {
    for (auto c : adj[i]) {
      if (root[c] != root[i])
        condensation_graph[root[i]].push_back(root[c]);
    }
  }

  //  end of Kosaraju

  order.clear();
  used.assign(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    if (!used[root[i]])
      dfs(root[i], order, used, condensation_graph);
  }

  // topological sort of condensation graph

  vector<bitset<50005>> dp(N + 1);

  for (auto c : order) {
    dp[c][c] = 1;
    for (auto u : condensation_graph[c]) {
      dp[c] |= dp[u];
    }
  }

  while (Q--) {
    int a, b;
    cin >> a >> b;

    if (dp[root[a]][root[b]])
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }

  // the solve of the problem

  return 0;
}