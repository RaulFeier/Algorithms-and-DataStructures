#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct Node {
  i64 val;
  i64 freq;

  Node() { val = 0, freq = 0; }

  Node(int val, int freq) {
    this->val = val;
    this->freq = freq;
  }
};

Node combine(Node a, Node b) {
  if (a.val < b.val)
    return a;
  else if (a.val > b.val)
    return b;
  else
    return Node(a.val, a.freq + b.freq);
}

template <typename T> class Segtree {
private:
  vector<T> tree;
  int N;

  void update(int node, int l, int r, int pos, i64 val) {
    if (l == r) {
      tree[node].val = val;
      tree[node].freq = 1;
      return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid) {
      update(node << 1, l, mid, pos, val);
    } else {
      update((node << 1) + 1, mid + 1, r, pos, val);
    }

    tree[node] = combine(tree[node << 1], tree[(node << 1) + 1]);
  }

  T query(int node, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return tree[node];
    }

    int mid = (l + r) >> 1;

    T aux(1e9, 0);
    if (a <= mid)
      aux = combine(aux, query(node << 1, l, mid, a, b));

    if (b > mid)
      aux = combine(aux, query((node << 1) + 1, mid + 1, r, a, b));

    return aux;
  }

public:
  Segtree(int n) {
    tree.assign(4 * n + 5, T());
    N = n;
  }

  void update(int pos, int val) { update(1, 1, N, pos, val); }

  T query(int a, int b) { return query(1, 1, N, a, b); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
