#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 200010;

string P, T;
int N, M;

int b[N_MAX];

void kmpPreprocess() {
  int i = 0, j = -1;
  b[0] = -1;

  while (i < M) {
    while ((j >= 0) && (P[i] != P[j]))
      j = b[j];

    i++, j++;
    b[i] = j;
  }
}

int kmpSearch() {
  int freq = 0;
  int i = 0, j = 0;

  while (i < N) {
    while ((j >= 0) && (T[i] != P[j]))
      j = b[j];

    i++, j++;

    if (j == M) {
      freq++;
      j = b[j];
    }
  }

  return freq;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T >> P;
  M = P.size();
  N = T.size();
  kmpPreprocess();

  cout << kmpSearch() << '\n';

  return 0;
}
