#include "../HEADER.h"

class ftree {
private:
  vi64 ft;

  i64 lsbl(i64 x) { return x & (-x); }

public:
  ftree(i64 n) {
    ft.assign(n + 1, 0); // if index from 0 add 1
  }

  void update(i64 i, i64 val) {
    i64 crt = i + 1; // add 1 index from 0

    while (crt < ft.size()) {
      ft[crt] += val;
      crt += lsbl(crt);
    }
  }

  i64 sum(i64 from) {
    from += 1; // add 1 index from 0

    i64 sum = 0;
    while (from > 0) {
      sum += ft[from];
      from -= lsbl(from);
    }

    return sum;
  }

  i64 sum(i64 from, i64 to) { return sum(to) - sum(from); }
};

int main() {
  i64 n;
  cin >> n;

  ftree f(n);
  return 0;
}
