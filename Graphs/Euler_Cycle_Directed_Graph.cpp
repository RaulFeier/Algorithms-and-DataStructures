// https://cses.fi/problemset/task/1693/
#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &order) {
  while (!adj[node].empty()) {
    auto c = adj[node].back();
    adj[node].pop_back();

    dfs(c.first, adj, order);
  }

  order.push_back(node);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<pair<int, int>>> adj(N + 1);
  vector<int> degree_in(N + 1, 0), degree_out(N + 1, 0);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back({v, i});
    degree_out[u]++;
    degree_in[v]++;
  }

  for (int i = 2; i <= N - 1; i++) {
    if ((degree_in[i] + degree_out[i]) & 1 ||
        degree_out[1] - 1 != degree_in[1] ||
        degree_in[N] - 1 != degree_out[N]) {
      cout << "IMPOSSIBLE" << '\n';
      return 0;
    }
  }

  vector<int> order;

  dfs(1, adj, order);

  reverse(order.begin(), order.end());

  if (order.size() != M + 1 || order.back() != N)
    cout << "IMPOSSIBLE" << '\n';
  else {
    for (auto c : order)
      cout << c << " ";
    cout << '\n';
  }

  return 0;
}

/*

 */
