#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
  int n, m;
  vector<vector<int>> a;

  Matrix() {}

  Matrix(int _n, int _m) {
    n = _n;
    m = _m;
    a.assign(n, vector<int>(m, 0));
  }

  Matrix(vector<vector<int>> v) {
    n = v.size();
    m = n ? v[0].size() : 0;
    a = v;
  }

  inline void make_unit() {
    assert(n == m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        a[i][j] = i == j;
    }
  }

  inline Matrix operator+(const Matrix &aux) {
    Matrix ans(n, m);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] + aux.a[i][j]) % MOD;
      }
    }

    return ans;
  }

  inline Matrix operator-(const Matrix &aux) {
    Matrix ans(n, m);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] - aux.a[i][j] + MOD) % MOD;
      }
    }

    return ans;
  }

  inline Matrix operator*(const Matrix &aux) {
    Matrix ans(n, aux.m);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < aux.m; j++) {
        for (int k = 0; k < m; k++) {
          ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * aux.a[k][j] % MOD) % MOD;
        }
      }
    }
    return ans;
  }

  inline Matrix pow(long long k) {
    assert(n == m);
    Matrix ans(n, n), t = a;
    ans.make_unit();

    while (k) {
      if (k & 1)
        ans = ans * t;
      t = t * t;
      k >>= 1;
    }

    return ans;
  }
};
