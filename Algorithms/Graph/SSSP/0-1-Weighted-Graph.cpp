#include "../../../HEADER.h"

int main() {
  i64 v, e;
  cin >> v >> e;

  vector<vp64> graph(v);

  for (i64 i : range(e)) {
    int a, b;
    cin >> a >> b;

    graph[a].emplace_back(b, 0);
    graph[b].emplace_back(a, 0);
  }

  i64 start_vertex;
  cin >> start_vertex;
  i64 end_vertex;
  cin >> end_vertex;

  vi64 dist(v, INF);
  dist[start_vertex] = 0;
  queue<i64> q;
  q.push(start_vertex);

  while (!q.empty()) {
    i64 crt = q.front();
    q.pop();

    for (auto &x : graph[crt]) {
      if (dist[x.first] == INF) {
        dist[x.first] = dist[crt] + 1;
        q.push(v);
      }
    }
  }

  cout << dist[end_vertex] << endl;

  return 0;
}