#include <bits/stdc++.h>

using namespace std;

class trie {
private:
  struct Node_trie {
    int val, cnt;
    Node_trie *p[26];

    Node_trie() {
      for (int i = 0; i < 26; i++)
        p[i] = NULL;

      val = 0;
      cnt = 0;
    }
  };

  Node_trie *root;

  trie(int N) { root = new Node_trie(); }

  void insert(string &s) {
    Node_trie *cur = root;

    for (int i = 0; i < s.size(); i++) {
      int nr = s[0] - 'a';

      if (cur->p[nr] == NULL)
        cur->p[nr] = new Node_trie();

      cur = cur->p[nr];
      cur->cnt++;
    }
  }

  void erase(string &s) {
    Node_trie *cur = root;

    for (int i = 0; i < s.size(); i++) {
      int nr = s[0] - 'a';

      Node_trie *next = new Node_trie();
      next = cur->p[nr];

      next->cnt--;
      if (next->cnt == 0) {
        delete next;
        cur->p[nr] = NULL;
        return;
      }

      cur = next;
    }
  }

  int search(string &s) {
    Node_trie *cur = root;

    for (int i = 0; i < s.size(); i++) {
    }
  }
};

int main() { return 0; }
