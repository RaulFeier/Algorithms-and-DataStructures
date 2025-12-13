#include <bits/stdc++.h>

using namespace std;

template <class T> class BIT1D {
private:
  vector<T> tree;

public:
  BIT1D(int N) { tree.assign(N + 1, 0); }

  void update(int pos, T val) {
    for (int i = pos; i < (int)tree.size(); i += (i & (-i))) {
      tree[i] += val;
    }
  }

  T range_query(int pos) {
    T sum = 0;
    for (int i = pos; i > 0; i -= (i & (-i))) {
      sum += tree[i];
    }

    return sum;
  }

  T query(int a, int b) { return range_query(b) - range_query(a - 1); }
};

template <class T> class BIT2D {
private:
  vector<vector<T>> tree;

public:
  BIT2D(int N, int M) { tree.assign(N + 1, vector<T>(M + 1, 0)); }

  void update(int x, int y, int val) {
    for (int i = x; i < tree.size(); i += (i & (-i))) {
      for (int j = y; j < tree[0].size(); j += (j & (-j))) {
        tree[i][j] += val;
      }
    }
  }

  T range_query(int x, int y) {
    T sum = 0;
    for (int i = x; i > 0; i -= (i & (-i))) {
      for (int j = y; j > 0; j -= (j & (-j))) {
        sum += tree[i][j];
      }
    }

    return sum;
  }

  T query(int x1, int y1, int x2, int y2) {
    return range_query(x2, y2) - range_query(x2, y1 - 1) -
           range_query(x1 - 1, y2) + range_query(x1 - 1, y1 - 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  BIT2D<int> fen(4, 4);
}
