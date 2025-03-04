#include <bits/stdc++.h>

using namespace std;

// here i have a matrix of size 3x3 but it can be changed

// O(K^3 * log(N)) where K is the size of the matrix and N is the power

vector<vector<int>> matrix_multiplication(vector<vector<int>> &a,
                                          vector<vector<int>> &b) {
  vector<vector<int>> res(3, vector<int>(3, 0));

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        res[i][j] = (res[i][j] + 1ll * a[i][k] * b[k][j]);
      }
    }
  }

  return res;
}

vector<vector<int>> solve(vector<vector<int>> &v, int b) {
  if (b == 0) {
    return {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  } else if (b & 1) {
    auto aux = solve(v, b - 1);
    return matrix_multiplication(v, aux);
  }

  auto aux = solve(v, b / 2);
  return matrix_multiplication(aux, aux);
}