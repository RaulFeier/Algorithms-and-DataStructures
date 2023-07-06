#include "../HEADER.h"

class UnionFind {
private:
  vi64 p, rank, setSize;
  i64 numSets;

public:
  UnionFind(i64 n) {
    p.assign(n, 0);
    for (i64 i : range(n))
      p[i] = i;
    rank.assign(n, 0);
    setSize.assign(n, 1);
    numSets = n;
  }

  i64 findSet(i64 i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  i64 numDisjointSets() { return numSets; }
  i64 sizeOfSet(i64 i) { return setSize[findSet(i)]; }

  void unionSet(int i, int j) {
    if (isSameSet(i, j))
      return;
    i64 x = findSet(i), y = findSet(j);
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
