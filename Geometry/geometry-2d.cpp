#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9; // default error

// Point double
struct Point {
  long double x, y;

  friend istream &operator>>(istream &in, Point &other) {
    in >> other.x >> other.y;
    return in;
  }

  friend ostream &operator<<(ostream &out, Point &other) {
    out << other.x << " " << other.y;
    return out;
  }

  bool operator<(const Point &other) {
    if (fabs(x - other.x) > EPS)
      return x < other.x; // by x-coordinate
    return y < other.y;
  }

  bool operator==(const Point &other) {
    return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
  }
};

namespace double_point {
double euclidean_dist(const Point &a, const Point &b) { // return dist^2
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double manhattan_dist(const Point &a, const Point &b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

bool colinear(Point a, Point b, Point c) {
  return a.x * b.y + a.y * c.x + b.x * c.y - c.x * b.y - b.x * a.y -
             a.x * c.y ==
         0;
}

// standing at point a facing point b if c is on the right then the formula is
// negative and it turns clock_wise, if the formula is positive it turn
// trigonometric way
bool clock_wise(Point a, Point b, Point c) {
  return (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y) < 0;
}
} // namespace double_point

// line stuff

struct line {
  long double a, b, c;
};

line pointsToLine(Point p1, Point p2) {
  if (p1.x == p2.x)                          // vertical line is fine
    return {1.0, 0.0, -(long double)(p1.x)}; // default values
  else {
    double a = -(long double)(p1.y - p2.y) / (p1.x - p2.x);
    return {a, 1.0, -(long double)(a * p1.x) - p1.y}; // NOTE: b always 1.0
  }
}

bool areParallel(line l1, line l2) { // check a & b
  return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areIntersect(line l1, line l2, Point &p) {
  if (areParallel(l1, l2))
    return false; // no intersection
  // solve system of 2 linear algebraic equations with 2 unknowns
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  // special case: test for vertical line to avoid division by zero
  if (fabs(l1.b) > EPS)
    p.y = -(l1.a * p.x + l1.c);
  else
    p.y = -(l2.a * p.x + l2.c);
  return true;
}

// Point_int
struct Point_i {
  int x, y;

  friend istream &operator>>(istream &in, Point_i &other) {
    in >> other.x >> other.y;
    return in;
  }

  friend ostream &operator<<(ostream &out, Point_i &other) {
    out << other.x << " " << other.y;
    return out;
  }

  bool operator<(const Point_i &other) {
    if (other.x != x)
      return x < other.x; // by x-coordinate
    return y < other.y;
  }

  bool operator==(const Point &other) { return (x == other.x && y == other.y); }
};

int insideCircle(Point_i p, Point_i c, int r) { // all integer version
  int dx = p.x - c.x, dy = p.y - c.y;
  int Euc = dx * dx + dy * dy, rSq = r * r;   // all integer
  return Euc < rSq ? 1 : Euc == rSq ? 0 : -1; // inside/border/outside
}

// Area of a polygon
int polygon_area(vector<Point_i> &a) {
  int sum = 0;
  for (int i = 0; i < (int)a.size() - 1; i++) {
    sum += (a[i].x * a[i + 1].y - a[i + 1].x * a[i].y);
  }

  return abs(sum); // where d = sum^2
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Point a, b, c;
  cin >> a >> b >> c;

  bool ok = double_point::clock_wise(a, b, c);

  return 0;
}
