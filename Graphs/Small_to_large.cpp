#include <bits/stdc++.h>

using namespace std;

set<int> arr[(int)2e5 + 5];
vector<vector<int>> adj;
vector<int> ans;

void dfs(int node, int parent) {
  for (auto c : adj[node]) {
    if (c == parent)
      continue;

    dfs(c, node);

    if (arr[c].size() > arr[node].size()) {
      swap(arr[c], arr[node]);
    }

    for (auto e : arr[c])
      arr[node].insert(e);
  }

  ans[node] = arr[node].size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  adj.resize(N + 1);
  ans.resize(N + 1);

  for (int i = 1; i <= N; i++) {
    int color;
    cin >> color;

    arr[i].insert(color);
  }

  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, -1);

  for (int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';

  return 0;
}