#include "../../../HEADER.h"

void Bellman_Ford(const vector<vector<p64>> &g, i64 s) {
  vec<i64> dist(g.size(), INF);
  dist[s] = 0;

  for (i64 i = 0; i < g.size() - 1; i++) {
    bool modified = false;
    for (i64 j = 0; j < g.size(); j++) {
      if (dist[j] != INF) {
        for (auto &c : g[j]) {
          if (dist[j] + c.second >= dist[c.first]) {
            continue;
          }

          dist[c.first] = dist[j] + c.second;
          modified = true;
        }
      }
    }

    if (!modified) {
      break;
    }
  }

  vector<bool> isInCycle(g.size(), false);
  queue<i64> que;

  for (i64 i = 0; i < g.size(); i++) {
    if (dist[i] != INF) {
      for (auto &c : g[i]) {
        if (dist[i] + c.second < dist[c.first]) {
          que.push(c.first);
        }
      }
    }
  }

  while (!que.empty()) {
    i64 crt = que.front();
    que.pop();

    isInCycle[crt] = true;
    for (auto &c : g[crt]) {
      if (!isInCycle[c.first]) {
        que.push(c.first);
      }
    }
  }
}