#include <bits/stdc++.h>

using namespace std;

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

    dfs(c, node, dp, adj);
  }
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

  dfs(1, -1, dp, adj);

  while (Q--) {
    int a, x;
    cin >> a >> x;

    // the x parent of a in log time
    for (int k = 0; k < 20; k++) {
      if (x & (1 << k) && a != -1) {
        a = dp[a][k];
      }
    }

    cout << a << '\n';
  }

  return 0;
}