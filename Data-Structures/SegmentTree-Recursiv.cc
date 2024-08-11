#include <bits/stdc++.h>

using namespace std;

const int max_N = 200000;
int t[max_N + 5];
int lazy[max_N + 5];

void build(int node, int l, int r, vector<int> &v) {
  if (l == r) {
    t[node] = v[l - 1];
    return;
  }

  int mid = (l + r) / 2;
  build(node * 2, l, mid, v);
  build(node * 2 + 1, mid + 1, r, v);

  t[node] = min(t[node * 2], t[node * 2 + 1]);
}

void propagate(int node, int l, int r) {
  if (lazy[node] != 0) {
    t[node] = lazy[node];

    if (l != r) {
      lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
    } else {
      t[l] = lazy[node];
    }
    lazy[node] = 0;
  }
}

void update_lazy(int node, int l, int r, int a, int b, int val) {
  propagate(node, l, r);

  if (a <= l && r <= b) {
    lazy[node] = val;
    propagate(node, l, r);
    return;
  }

  int mid = (l + r) / 2;
  if (a <= mid) {
    update_lazy(node * 2, l, mid, a, b, val);
  }

  if (b > mid) {
    update_lazy(node * 2 + 1, mid + 1, b, a, b, val);
  }

  int lsubtree = (lazy[node * 2] != 0) ? lazy[node * 2] : t[node * 2];
  int rsubtree =
      (lazy[node * 2 + 1] != 0) ? lazy[node * 2 + 1] : t[node * 2 + 1];
  t[node] = min(lsubtree, rsubtree);
}

void query_lazy(int node, int l, int r, int a, int b, int &val) {
  propagate(node, l, r);
  if (a <= l && r <= b) {
    val = min(val, t[node]);
  }
  int mid = (l + r) / 2;

  if (a <= mid) {
    query_lazy(node * 2, l, mid, a, b, val);
  }

  if (b > mid) {
    query_lazy(node * 2 + 1, mid + 1, b, a, b, val);
  }
}

void update(int node, int l, int r, int pos, int val) {
  if (l == r) {
    t[node] = val;
    return;
  }

  int mid = (l + r) / 2;
  if (pos <= mid) {
    update(node * 2, l, mid, pos, val);
  } else {
    update(node * 2 + 1, mid + 1, r, pos, val);
  }

  t[node] = min(t[node * 2], t[node * 2 + 1]);
}

void query(int node, int l, int r, int a, int b, int &val) {
  if (a <= l && r <= b) {
    val = min(val, t[node]);
    return;
  }

  int mid = (l + r) / 2;
  if (a <= mid) {
    query(node * 2, l, mid, a, b, val);
  }

  if (b > mid) {
    query(node * 2 + 1, mid + 1, r, a, b, val);
  }
}
