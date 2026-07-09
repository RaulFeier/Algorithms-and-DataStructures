// https://open.kattis.com/problems/convexhull
#include <bits/stdc++.h>

using namespace std;

struct Point {
  double x, y;
  bool operator==(Point const &t) const { return x == t.x && y == t.y; }
};

int orientation(Point a, Point b, Point c) {
  double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
  if (v < 0)
    return -1; // clockwise
  if (v > 0)
    return +1; // counter-clockwise
  return 0;
}

bool clock_wise(Point a, Point b, Point c) {
  int o = orientation(a, b, c);
  return o < 0;
}

vector<Point> convex_hull(vector<Point> &points) {
  Point p = *min_element(points.begin(), points.end(),
                         [](const Point &a, const Point &b) -> bool {
                           return make_pair(a.y, a.x) < make_pair(b.y, b.x);
                         });

  sort(points.begin(), points.end(),
       [&](const Point &a, const Point &b) -> bool {
         int o = orientation(p, a, b);
         if (o == 0) {
           return (p.x - a.x) * (p.x - a.x) + (p.y - a.y) * (p.y - a.y) <
                  (p.x - b.x) * (p.x - b.x) + (p.y - b.y) * (p.y - b.y);
         }
         return o < 0;
       });

  vector<Point> st; // stack for the convex hull
  for (int i = 0; i < (int)points.size(); i++) {
    while (st.size() > 1 &&
           !clock_wise(st[st.size() - 2], st.back(), points[i]))
      st.pop_back();

    st.push_back(points[i]);
  }

  // remove duplicate points
  vector<Point> convex_hull;
  convex_hull.reserve(int(st.size()));

  for (int i = 0; i < (int)st.size() - 1; i++) {
    if (st[i].x != st[i + 1].x || st[i].y != st[i + 1].y)
      convex_hull.push_back(st[i]);
  }
  convex_hull.push_back(st.back());

  return convex_hull;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    int N;
    cin >> N;

    if (!N)
      break;

    vector<Point> Points(N);
    for (auto &c : Points) {
      cin >> c.x >> c.y;
    }

    auto v = convex_hull(Points);

    cout << v.size() << '\n';
    reverse(v.begin(), v.end());
    for (auto &c : v)
      cout << c.x << " " << c.y << '\n';
  }

  return 0;
}
