#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 9;

struct st {
  int a, b, cost;
} e[N];

const int INF = 2e9;

int main() {
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++)
    cin >> e[i].a >> e[i].b >> e[i].cost;

  int s;
  cin >> s; // is there any negative cycle which is reachable from s?
  vector<int> d(N + 1, INF); // for finding any cycle(not necessarily from s)
                             // set d[i] = 0 for all i
  d[s] = 0;
  vector<int> p(N + 1, -1);
  int x;

  for (int i = 1; i <= N; i++) {
    x = -1;
    for (int j = 0; j < M; j++) {
      if (d[e[j].a] < INF) {
        if (d[e[j].b] > d[e[j].a] + e[j].cost) {
          d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost); // for overflow
          p[e[j].b] = e[j].a;
          x = e[j].b;
        }
      }
    }
  }

  if (x == -1)
    cout << "No negative cycle from " << s;
  else {
    int y = x; // x can be on any cycle or reachable from some cycle
    for (int i = 0; i < N; i++)
      y = p[y];

    vector<int> path;
    for (int cur = y;; cur = p[cur]) {
      path.push_back(cur);
      if (cur == y && path.size() > 1)
        break;
    }
    reverse(path.begin(), path.end());

    cout << "Negative cycle: ";
    for (int i = 0; i < path.size(); ++i)
      cout << path[i] << ' ';
  }

  return 0;
}