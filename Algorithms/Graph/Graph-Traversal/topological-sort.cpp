#include "../../../HEADER.h"

graph g;
vi64 ts;
vector<bool> visit;

void toposort(i64 node) {
  visit[node] = true;
  for (auto &c : g[node]) {
    if (!visit[c]) {
      toposort(c);
    }
  }
  ts.push_back(node);
}

int main() {
  i64 n, m;
  cin >> n >> m;

  g.assign(n, vi64());
  visit.assign(n, false);

  for (i64 i = 0; i < m; i++) {
    i64 a, b;
    cin >> a >> b;

    g[a].push_back(b);
  }

  for (i64 i = 0; i < n; i++) {
    if (!visit[i]) {
      toposort(i);
    }
  }

  // you can sort ts or go from the back to the front to dont lose time

  return 0;
}