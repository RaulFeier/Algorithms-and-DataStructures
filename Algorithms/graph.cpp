#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

void Bellman_Ford(const vector<vector<pair<int, int>>> &g, int s) {
  vector<int> dist(g.size(), INF);
  dist[s] = 0;

  for (int i = 0; i < g.size() - 1; i++) {
    bool modified = false;
    for (int j = 0; j < g.size(); j++) {
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

  queue<int> que;

  for (int i = 0; i < g.size(); i++) {
    if (dist[i] != INF) {
      for (auto &c : g[i]) {
        if (dist[i] + c.second < dist[c.first]) {
          que.push(c.first);
        }
      }
    }
  }

  vector<bool> isInCycle(g.size(), false);

  while (!que.empty()) {
    int crt = que.front();
    que.pop();

    isInCycle[crt] = true;
    for (auto &c : g[crt]) {
      if (!isInCycle[c.first]) {
        que.push(c.first);
      }
    }
  }
}

const vector<int> dirx = {1, -1, 0, 0};
const vector<int> diry = {0, 0, 1, -1};

void bfs_2d(const vector<vector<int>> &v, pair<int, int> start_point) {
  deque<pair<int, int>> q;
  q.push_back(start_point);
  vector<vector<bool>> visit(v.size(), vector<bool>(v[0].size(), false));
  visit[start_point.first][start_point.second] = true;

  while (!q.empty()) {
    auto crt = q.front();
    q.pop_front();

    for (int i = 0; i < 4; i++) {
      int x = crt.first + dirx[i];
      int y = crt.second + diry[i];

      if (x >= 0 && x < v.size() && y >= 0 && y < v[0].size() && !visit[x][y]) {
        q.push_back({x, y});
        visit[x][y] = true;
      }
    }
  }
}

void Bipartite_Graph(const vector<vector<int>> &g) {
  int s = 0; // node start
  queue<int> q;
  q.push(s);

  bool isBipartite = true;
  vector<int> color(g.size(), INF);
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
}

enum { Unvisited = -1 };

vector<int> dfs_num, dfs_low, dfs_parent, articulation_node;
vector<vector<int>> adj;
int cnt;

void ArticulationPoints_and_Bridges(int node) {
  dfs_low[node] = dfs_num[node] = cnt;

  for (auto &c : adj[node]) {
    if (dfs_num[c] == Unvisited) {
      dfs_parent[c] = node;
      ArticulationPoints_and_Bridges(c);

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

vector<int> color;
vector<int> parent;

enum { unvisited = 0, explored = 1, visited = 2 };

bool cycle(vector<vector<int>> &g, int node, int &start, int &end) {
  int par = parent[node];
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

vector<int> dij(vector<vector<pair<int, int>>> &g, int s) {
  vector<int> ans(g.size() + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  ans[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    auto crt = pq.top();
    pq.pop();

    if (crt.first > ans[crt.second]) {
      continue;
    }

    for (auto &c : g[crt.second]) {
      int cand = crt.first + c.second;
      if (cand < ans[c.first]) {
        ans[c.first] = cand;
        pq.push({cand, c.first});
      }
    }
  }

  return ans;
}