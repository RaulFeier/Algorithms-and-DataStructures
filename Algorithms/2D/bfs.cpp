#include "../../HEADER.h"

const vi64 dirx = {1, -1, 0, 0};
const vi64 diry = {0, 0, 1, -1};

void bfs(const vv &v, p64 start_point) {
  deque<p64> q;
  q.push_back(start_point);
  vec<vb> visit(v.size(), vb(v[0].size(), false));
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

int main() {
  vv m(3, vi64(3, 0));

  // read 2D
  p64 start_point = {1, 1};

  bfs(m, start_point);

  return 0;
}