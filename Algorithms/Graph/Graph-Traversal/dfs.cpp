#include "../../../HEADER.h"

void dfs(vector<vector<i64>> &g, i64 node, vector<bool> &visit) {
  visit[node] = true;

  for (auto &c : g[node]) {
    if (!visit[c]) {
      dfs(g, c, visit);
    }
  }
}