#include <bits/stdc++.h>

using namespace std;

template <class T> class Sqrt {
private:
  int blocksize;
  vector<T> data, nums;

public:
  Sqrt(int s, vector<T> &a) : blocksize(s), data(s, 0) {
    nums = a;
    for (int i = 1; i < (int)nums.size(); i++) {
      data[i / blocksize] += nums[i];
    }
  }

  void update(int pos, T val) {
    data[pos / blocksize] -= nums[pos];
    nums[pos] = val;
    data[pos / blocksize] += nums[pos];
  }

  T range_query(int pos) {
    T Sum = 0;
    for (int i = 0; i < pos / blocksize; i++) {
      Sum += data[i];
    }

    for (int i = (pos / blocksize) * blocksize; i <= pos; i++) {
      Sum += nums[i];
    }

    return Sum;
  }

  T query(int l, int r) { return range_query(r) - range_query(l - 1); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, Q;
  cin >> N >> Q;

  vector<int64_t> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  Sqrt<int64_t> sq((int)ceil(sqrt(a.size())), a);

  while (Q--) {
    int type, l, r;
    cin >> type >> l >> r;

    if (type == 1) {
      sq.update(l, 1ll * r);
    } else {
      cout << sq.query(l, r) << '\n';
    }
  }

  return 0;
}
