// https://cses.fi/problemset/result/17067385/
// for a given Points tell if they are inside or outside of a polygon
#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x, y;

  friend istream &operator>>(istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
  }
};

long long direction(Point p1, Point p2, Point p) {
  return 1ll * (p.y - p1.y) * (p2.x - p1.x) -
         1ll * (p.x - p1.x) * (p2.y - p1.y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<Point> polygon(N);

  for (auto &c : polygon)
    cin >> c;

  for (int i = 0; i < M; i++) {
    Point p;
    cin >> p;

    bool boundary = false;
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      int k = (j + 1) % N;

      if (direction(polygon[j], polygon[k], p) == 0 &&
          max(polygon[j].x, polygon[k].x) >= p.x &&
          min(polygon[j].x, polygon[k].x) <= p.x &&
          max(polygon[j].y, polygon[k].y) >= p.y &&
          min(polygon[j].y, polygon[k].y) <= p.y) {
        boundary = true;
        break;
      }

      // cout << j << " " << direction(polygon[j], polygon[k], p) << '\n';
      if (polygon[j].y > p.y && polygon[k].y <= p.y &&
          direction(polygon[j], polygon[k], p) < 0)
        cnt++;

      if (polygon[k].y > p.y && polygon[j].y <= p.y &&
          direction(polygon[j], polygon[k], p) > 0)
        cnt++;
    }

    if (boundary)
      cout << "BOUNDARY" << '\n';
    else if (cnt & 1)
      cout << "INSIDE" << '\n';
    else
      cout << "OUTSIDE" << '\n';
  }

  return 0;
}
