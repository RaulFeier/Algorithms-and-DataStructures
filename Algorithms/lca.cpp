#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
  vector<int> tree;
  int n;
  int len;

public:
  SegmentTree(vector<int> &height, vector<int> &in_out) {
    n = in_out.size();
    tree.resize(in_out.size() * 4, 1e9);
    len = n / 2;
    build(height, in_out);
  }

  void build(vector<int> &height, vector<int> &in_out) {
    for (int i = 0; i < in_out.size(); i++) {
      tree[i + len] = height[in_out[i]];
    }

    int start = len / 2;
    int end = len;

    while (start != 0) {
      for (int i = start - 1; i < end; i++) {
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
      }
      start /= 2;
      end /= 2;
    }
  }

  int query(int l, int r) {
    l = l + len - 1;
    r = r + len - 1;
    int res = 1e9;

    while (l <= r) {
      if (l % 2 == 1) {
        res = min(res, tree[l]);
        l++;
      }
      if (r % 2 == 0) {
        res = min(res, tree[r]);
        r--;
      }
      l /= 2;
      r /= 2;
    }

    return res;
  }
};

vector<int> first, height, in_out;
vector<bool> visited;

void dfs(vector<vector<int>> &adj, int node, int h) {
  visited[node] = true;
  height[node] = h;
  first[node] = in_out.size();
  in_out.push_back(node);

  for (auto &c : adj[node]) {
    if (!visited[c]) {
      dfs(adj, c, h + 1);
      in_out.push_back(node);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  first.resize(n);
  visited.resize(n, false);
  height.resize(n);
  in_out.reserve(n * 2);

  SegmentTree segtree(height, in_out);

  // querys

  int left = first[3];
  int right = first[4];
  if (left > right) {
    swap(left, right);
  }

  cout << segtree.query(left, right) << endl;

  return 0;
}