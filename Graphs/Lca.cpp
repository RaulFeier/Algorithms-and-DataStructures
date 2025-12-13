#include <bits/stdc++.h>

using namespace std;
vector<int> h;

void dfs(int node, int p, vector<vector<int>> &dp, vector<vector<int>> &adj) {
  dp[node][0] = p;

  for (int k = 1; k < 20; k++) {
    int half = dp[node][k - 1];
    if (half != -1)
      dp[node][k] = dp[half][k - 1];
  }

  for (auto c : adj[node]) {
    if (c == p)
      continue;

    h[c] = h[node] + 1;
    dfs(c, node, dp, adj);
  }
}

int lca(int a, int b, vector<vector<int>> &dp) {
  if (h[a] > h[b])
    swap(a, b);

  int diff = h[b] - h[a];

  for (int k = 0; k < 20; k++) {
    if ((1 << k) & diff) {
      b = dp[b][k];
    }
  }

  if (a == b)
    return a;

  for (int k = 19; k >= 0; k--) {
    if (dp[a][k] != dp[b][k]) {
      a = dp[a][k];
      b = dp[b][k];
    }
  }

  return dp[a][0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> adj(N + 1);

  for (int i = 0; i < N; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> dp(N + 1,
                         vector<int>(20, -1)); // dp[i][k] - the 2^k parent of i
  h.assign(N + 1, -1);
  h[1] = 0;

  dfs(1, -1, dp, adj);

  while (Q--) {
    int a, b;
    cin >> a >> b;

    cout << lca(a, b, dp) << '\n';
  }

  return 0;
}