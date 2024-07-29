#include <bits/stdc++.h>

using namespace std;

int l_bsearch(vector<int> &v, int value) {
  int l = 0, r = v.size() - 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (v[mid] < value) {
      l = mid + 1;
    } else if (v[mid] >= value) {
      r = mid;
    }
  }

  return r;
}

int u_bsearch(vector<int> &v, int value) {
  int l = 0, r = v.size() - 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (v[mid] <= value) {
      l = mid + 1;
    } else if (v[mid] > value) {
      r = mid;
    }
  }

  return r;
}

const double EPS = 1e-9;

double f(double x) {
  // some function that the problem has
}

int ternary_search() {
  double l = 0.0, r = 10000.0; // set whatever the range values are

  while (r - l > EPS) {
    double delta = (r - l) / 3.0;
    double m1 = l + delta;
    double m2 = r - delta;

    if (f(m1) > f(m2)) {
      l = m1;
    } else {
      r = m2;
    }
  }

  return l;
}

int main() {
  vector<int> v = {1, 1, 2, 2, 3, 3, 3};

  cout << l_bsearch(v, 3) << '\n';
  cout << u_bsearch(v, 3) << '\n';
}