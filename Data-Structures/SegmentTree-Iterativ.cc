#include <bits/stdc++.h>

using namespace std;

const int max_N = 200000;
int t[max_N + 5];
int N; // size of the vector;

void build(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    t[i + N] = v[i];
  }

  int start = N / 2;
  int end = N;

  while (start > 0) {
    for (int i = start - 1; i < end; i++) {
      t[i] = min(t[i * 2], t[i * 2 + 1]);
    }

    start /= 2;
    end /= 2;
  }
}

void update(int pos, int val) {
  pos += N - 1;
  t[pos] = val;

  pos /= 2;

  while (pos > 0) {
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
    pos /= 2;
  }
}

int query(int l, int r) {
  l += N - 1;
  r += N - 1;

  int res = -1;
  while (l <= r) {
    if (l % 2 == 1) {
      res = max(res, t[l]);
      l++;
    }

    if (r % 2 == 0) {
      res = max(res, t[r]);
      r--;
    }

    l /= 2;
    r /= 2;
  }

  return res;
}
