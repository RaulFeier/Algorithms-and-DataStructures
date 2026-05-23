#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
  vector<vector<int>> tree;
  vector<bool> final_word;
  int next_node;

  Trie(int N) {
    tree.assign(N, vector<int>(26, 0));
    final_word.assign(N, false);
    next_node = 0;
  }

  void insert(string &s) {
    int node = 0; // start node
    for (auto &c : s) {
      if (tree[node][c - 'a'] == 0)
        tree[node][c - 'a'] = ++next_node;

      node = tree[node][c - 'a'];
    }

    final_word[node] = true;
  }

  bool search(string &s) {
    int node = 0;
    for (auto &c : s) {
      if (tree[node][c - 'a'] == 0)
        return false; // the prefix doesnt exist

      node = tree[node][c - 'a'];
    }

    return true;
  }
};

int main() { return 0; }
