#include "../../../HEADER.h"

vi64 color;
vi64 parent;

enum { unvisited = 0, explored = 1, visited = 2 };

bool cycle(graph &g, i64 node, i64 &start, i64 &end) {
  i64 par = parent[node];
  color[node] = explored;

  for (auto &c : g[node]) {
    if (c == par) {
      continue;
    }
    if (color[c] == unvisited) {
      parent[c] = node;
      if (cycle(g, c, start, end)) {
        return true;
      }
    } else if (color[c] == explored) {
      start = node;
      end = c; // obtional to see where the cycle ends;
      return true;
    }
  }

  color[node] = visited;
  return false;
}

int main() {
  i64 n, m;
  cin >> n >> m;

  graph g(n);
  for (i64 i = 0; i < m; i++) {
    i64 a, b;
    cin >> a >> b;
    g[a].push_back(b); // directed graph
  }

  color.assign(n, 0);
  parent.assign(n, -1);
  i64 end;
  i64 start;

  for (i64 i = 0; i < n; i++) {
    if (cycle(g, i, start, end) and color[i] == unvisited) {
      // found cycle
      break;
    }
  }

  return 0;
}