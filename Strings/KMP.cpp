#include <bits/stdc++.h>

using namespace std;

// p[i] = len, the length of the longest prefix that matches a subtring that
// ends at position i
vector<int> prefix_function(string &s) {
  vector<int> p((int)s.size());
  p[0] = 0;

  for (int i = 1; i < (int)s.size(); i++) {
    int j = p[i - 1];

    while (j > 0 && s[i] != s[j]) {
      j = p[j - 1];
    }

    if (s[i] == s[j])
      j++;

    p[i] = j;
  }

  return p;
}

// how manny times S occurs in T
int kmpSearch(vector<int> &prefix_s, string &T, string &P) {
  int j = 0, cnt = 0;

  for (int i = 0; i < (int)T.size(); i++) {
    while (j > 0 && T[i] != P[j])
      j = prefix_s[j - 1];

    if (T[i] == P[j])
      j++;

    if (j == (int)P.size()) {
      cnt++;
      j = prefix_s[j - 1];
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string S = "aabaab";
  string T = "aabaabaabaab";

  auto p = prefix_function(S);
  cout << kmpSearch(p, T, S) << '\n';

  return 0;
}
