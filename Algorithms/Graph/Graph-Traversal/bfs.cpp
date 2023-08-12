#include "../../../HEADER.h"

void bfs(const vv &g, vb &visit, i64 start_vertex) {
  di64 q;
  q.pb(start_vertex);
  visit[start_vertex] = true;

  while (!q.empty()) {
    auto crt = q.front();
    q.pop_front();

    for (auto &x : g[crt]) {
      if (!visit[x]) {
        visit[x] = true;
        q.push_back(x);
      }
    }
  }
}

int main() {
  i64 n, m;
  cin >> n >> m; // size of graph

  vv g(n, vi64());

  for (i64 i = 0; i < m; i++) {
    i64 a, b;
    cin >> a >> b;

    g[a].pb(b);
  }

  vb visit(n, false);

  i64 start_vertex = 1;
  bfs(g, visit, start_vertex);

  return 0;
}