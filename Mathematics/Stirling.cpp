#include <bits/stdc++.h>

using namespace std;
const int MOD = 98999;

long long stirling_1(int N, int K) {
  vector<vector<long long>> dp(N + 1, vector<long long>(max(N, K) + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j] % MOD) % MOD;
    }
  }

  return dp[N][K];
}

long long stirling_2(int N, int K) {
  vector<vector<long long>> dp(N + 1, vector<long long>(max(N, K) + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + j * dp[i - 1][j] % MOD) % MOD;
    }
  }

  return dp[N][K];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    int c, a, b;
    cin >> c >> a >> b;

    if (c == 1) {
      cout << stirling_1(a, b) << '\n';
    } else
      cout << stirling_2(a, b) << '\n';
  }

  return 0;
}

/*
Stirling_1 calculates the number of permutations of lenght N with K cycles
Stirling_2 calculates the number of ways to divide a set into K nonempty subsets
*/
