#include "../../../HEADER.h"

enum { Unvisited = -1 };

vector<i64> dfs_num, dfs_low, dfs_parent, articulation_node;
vector<vector<i64>> adj;
i64 cnt;

void dfs(int node) {
  dfs_low[node] = dfs_num[node] = cnt;

  for (auto &c : adj[node]) {
    if (dfs_num[c] == Unvisited) {
      dfs_parent[c] = node;
      dfs(c);

      if (dfs_low[c] >= dfs_num[node]) {
        articulation_node.push_back(node);
      }

      if (dfs_low[c] > dfs_num[node]) {
        cout << "Bridge " << c << " " << node << endl;
      }
      dfs_low[node] = min(dfs_low[c], dfs_low[node]);
    } else if (c != dfs_parent[node]) {
      dfs_low[node] = min(dfs_low[node], dfs_num[c]);
    }
  }
}

int main() {
  i64 n, m;
  cin >> n >> m;

  adj.assign(n, vector<i64>());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_num.assign(n, Unvisited);
  dfs_low.assign(n, 0);
  dfs_parent.assign(n, -1);
  articulation_node.assign(n, 0);
  cnt = 0;

  for (int i = 0; i < n; i++) {
    if (dfs_num[i] == Unvisited) {
      dfs(i);
    }
  }

  return 0;
}