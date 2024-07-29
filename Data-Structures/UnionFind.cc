#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
  vector<int> p, rank, setSize;
  int numSets;

public:
  UnionFind(int n) {
    p.assign(n, 0);
    iota(p.begin(), p.end(), 0);
    rank.assign(n, 0);
    setSize.assign(n, 1);
    numSets = n;
  }

  int findSet(int i) {
    int t = i;
    while (p[i] != i) {
      i = p[i];
    }
    if (t != i) {
      p[t] = i;
    }
    return i;
  }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }

  void unionSet(int i, int j) {
    if (isSameSet(i, j))
      return;
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y])
      ++rank[y];
    setSize[y] += setSize[x];
    --numSets;
  }
};

int main() { UnionFind UF(5); }
