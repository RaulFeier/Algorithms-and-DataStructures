// https://infoarena.ro/problema/hamilton
// Minimum cost in a Hamiltonian cycle
#include <bits/stdc++.h>

using namespace std;

int dp[(1 << 18) + 1][18];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<pair<int, int>>> adj(N + 1);

  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
  }

  for (int i = 1; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = 1e9;
    }
  }

  dp[1][0] = 0;

  for (int i = 1; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      if (!((1 << j) & i))
        continue;

      for (auto c : adj[j]) {
        if (i & (1 << c.first))
          continue;

        int mask = i | (1 << c.first);
        dp[mask][c.first] = min(dp[mask][c.first], dp[i][j] + c.second);
      }
    }
  }

  int mn = 1e9;
  for (int i = 0; i < N; i++) {
    for (auto &c : adj[i]) {
      if (c.first == 0)
        mn = min(mn, dp[(1 << N) - 1][i] + c.second);
    }
  }

  if (mn == 1e9) {
    cout << "Nu exista solutie" << '\n';
  } else {
    cout << mn << '\n';
  }

  return 0;
}
