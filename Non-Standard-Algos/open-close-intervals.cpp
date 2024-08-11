#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N; // N events

  vector<int> oi(N);
  vector<int> ci(N);
  vector<pair<int, int>> v(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i].first >> v[i].second;
    oi[i] = i;
    ci[i] = i;
  }

  sort(oi.begin(), oi.end(),
       [&v](int a, int b) { return v[a].first < v[b].first; });
  sort(ci.begin(), ci.end(),
       [&v](int a, int b) { return v[a].second < v[b].second; });

  int time = 1;
  int a_given_time;
  int op = 0;
  int cl = 0;
  while (time <= a_given_time) {
    if (v[ci[cl]].second == time) {
      // do smt
      cl++;
    }

    if (v[oi[op]].first == time) {
      // do smt
      op++;
    }

    time++;
  }

  return 0;
}