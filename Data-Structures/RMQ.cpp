#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class RMQ {
private:
  vector<vector<int>> st;

public:
  RMQ(vector<int> &a) {
    st.resize(a.size() + 1, vector<int>(20)); // 0 indexed array

    for (int i = 0; i < a.size(); i++) {
      // cout << a[i] << " ";
      st[i + 1][0] = a[i];
    }
    // cout << '\n';

    for (int j = 1; j < 20; j++) {
      for (int i = 1; i + (1 << j) - 1 <= a.size(); i++) {
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int querie(int L, int R) {
    int j = 31 - __builtin_clz(R - L + 1);
    return min(st[L][j], st[R - (1 << j) + 1][j]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, Q;
  cin >> N >> Q;

  vector<int> a(N);

  for (auto &c : a)
    cin >> c;

  RMQ rmq(a);

  while (Q--) {
    int a, b;
    cin >> a >> b;

    cout << rmq.querie(a, b) << '\n';
  }

  return 0;
}
