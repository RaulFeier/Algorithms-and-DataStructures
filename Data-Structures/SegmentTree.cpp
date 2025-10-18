#include <bits/stdc++.h>

using namespace std;

class Node {
private:
public:
  int elem;

  Node() { elem = 1e9; }

  Node combine(Node a, Node b) {
    if (a.elem > b.elem)
      return b;

    return a;
  }
};

template <class T> class segtree {
private:
  vector<T> tree;

public:
  segtree(int N) { tree.assign(4 * N + 4, T()); }

  T get_elem(int pos) { return tree[pos]; }

  void update(int node, int l, int r, int pos, int elem) {
    if (l == r) {
      tree[node].elem = elem;
      return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
      update(node * 2, mid, l, pos, elem);
    } else {
      update(node * 2 + 1, mid + 1, r, pos, elem);
    }

    tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  segtree<Node> aint(5);
  aint.update(1, 1, 5, 3, 3);

  for (int i = 1; i <= 20; i++) {
    Node a = aint.get_elem(i);
    cout << a.elem << '\n';
  }

  return 0;
}
