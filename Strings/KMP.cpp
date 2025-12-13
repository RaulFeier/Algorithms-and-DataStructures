#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 200010;

string P, T; // here we look for P in T
int N, M;

int b[N_MAX];

void kmpPreprocess() {
  int i = 1, j = 0;
  b[0] = 0;

  while (i < M) {
    while ((j > 0) && (P[i] != P[j]))
      j = b[j - 1];

    if (P[i] == P[j])
      j++;

    b[i] = j;
    i++;
  }
}

int kmpSearch() {
  int freq = 0;
  int i = 0, j = 0;

  while (i < N) {
    while ((j > 0) && (T[i] != P[j]))
      j = b[j - 1];

    if (T[i] == P[j])
      j++;

    i++;

    if (j == M) {
      freq++;
      j = b[j - 1];
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

  for (int i = 0; i < M; i++) {
    cout << b[i] << " ";
  }
  cout << '\n';

  cout << kmpSearch() << '\n';

  return 0;
}
