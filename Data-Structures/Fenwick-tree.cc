#include <bits/stdc++.h>

using namespace std;

class ftree {
private:
  vector<int> ft;

  int lsbl(int x) { return x & (-x); }

public:
  ftree(int n) {
    ft.assign(n + 1, 0); // if index from 0 add 1
  }

  void update(int i, int val) {
    int crt = i + 1; // add 1 index from 0

    while (crt < ft.size()) {
      ft[crt] += val;
      crt += lsbl(crt);
    }
  }

  int sum(int from) {
    from += 1; // add 1 index from 0

    int sum = 0;
    while (from > 0) {
      sum += ft[from];
      from -= lsbl(from);
    }

    return sum;
  }

  int sum(int from, int to) { return sum(to) - sum(from); }
};

int main() {
  int n;
  cin >> n;

  ftree f(n);
  return 0;
}
