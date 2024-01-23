#include "../../../HEADER.h"

int main() {
  i64 n, m;
  cin >> n >> m;

  graph g(n);

  for (i64 i = 0; i < m; i++) {
    i64 a, b;
    cin >> a >> b;

    g[a].push_back(b); // directed graph
  }

  i64 s = 0; // node start
  queue<i64> q;
  q.push(s);

  bool isBipartite = true;
  vi64 color(n, INF);
  color[s] = 0;

  while (!q.empty() and isBipartite) {
    auto crt = q.front();
    q.pop();

    for (auto &c : g[crt]) {
      if (color[c] == INF) {
        color[c] = 1 - color[crt];
        q.push(c);
      } else if (color[c] == color[crt]) {
        isBipartite = false;
        break;
      }
    }
  }

  return 0;
}
