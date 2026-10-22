#include <bits/stdc++.h>

using namespace std;

class CentroidDecomp {
public:
  vector<vector<int>> adj;
  vector<bool> is_removed;
  vector<int> subtree_size;

  CentroidDecomp(int N) {
    adj.resize(N + 1);
    is_removed.assign(N + 1, false);
    subtree_size.assign(N + 1, 0);
  };

  int get_subtree_size(int node, int parent = -1) {
    subtree_size[node] = 1;
    for (int child : adj[node]) {
      if (child == parent || is_removed[child]) {
        continue;
      }
      subtree_size[node] += get_subtree_size(child, node);
    }
    return subtree_size[node];
  }

  int get_centroid(int node, int tree_size, int parent = -1) {
    for (int child : adj[node]) {
      if (child == parent || is_removed[child]) {
        continue;
      }
      if (subtree_size[child] * 2 > tree_size) {
        return get_centroid(child, tree_size, node);
      }
    }
    return node;
  }

  // write the function that does something

  void build_centroid_decomp(int node, int parent = -1) {
    int centroid = get_centroid(node, get_subtree_size(node));

    // do something

    is_removed[centroid] = true;
    for (int child : adj[centroid]) {
      if (is_removed[child]) {
        continue;
      }

      build_centroid_decomp(child, node);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
