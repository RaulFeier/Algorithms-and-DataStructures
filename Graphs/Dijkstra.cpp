#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void dij(vector<vector<pair<int, i64>>> &g) {
  vector<i64> dist(g.size(), 1e18);
  dist[1] = 0;

  priority_queue<pair<i64, int>, vector<pair<i64, int>>,
                 greater<pair<i64, int>>>
      pq;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto crt = pq.top();
    pq.pop();

    if (crt.first > dist[crt.second]) {
      continue;
    }

    for (auto &child : g[crt.second]) {
      i64 cand = crt.first + child.second;

      if (cand < dist[child.first]) {
        dist[child.first] = cand;
        pq.push({cand, child.first});
      }
    }
  }

  for (int i = 1; i < dist.size(); i++) {
    cout << dist[i] << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<pair<int, i64>>> g(N + 1);

  for (int i = 0; i < M; i++) {
    int u, v;
    i64 w;
    cin >> u >> v >> w;

    g[u].push_back({v, w});
  }

  dij(g);

  return 0;
}
