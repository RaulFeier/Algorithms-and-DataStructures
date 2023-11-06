#include "../../../HEADER.h"

inline void transpose(matrix &m) {
  i64 len = m.size();
  for (i64 i = 0; i < len; i++) {
    for (i64 j = 0; j < i; j++) {
      swap(m[i][j], m[j][i]);
    }
  }
}

inline void rtranspose(matrix &m) {
  i64 len = m.size() - 1;
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len - i; j++) {
      swap(m[i][j], m[len - j][len - i]);
    }
}

inline void hreverse(matrix &m) {
  i64 len = m.size();
  for (i64 i = 0; i < len; i++) {
    reverse(col(m[i]));
  }
}

inline void vreverse(matrix &m) {
  i64 len = m.size();
  for (i64 i = 0; i < len / 2; i++) {
    for (int j = 0; j < len; j++) {
      swap(m[i][j], m[len - 1 - i][j]);
    }
  }
}

inline void rotate_r(matrix &m) {
  transpose(m);
  hreverse(m);
}

inline void rotate_l(matrix &m) {
  hreverse(m);
  transpose(m);
}

inline void lshift(matrix &m, i64 line, i64 newf) {
  i64 len = m.size();
  rotate(m[line].begin(), m[line].begin() + newf, m[line].end());
}

inline bool same_diag(matrix &m, i64 i1, i64 j1, i64 i2, i64 j2) {
  return (i1 + j1 == i2 + j2) || (i1 - j1 == i2 - j2);
}

void print(matrix &m) {
  cout << endl;
  i64 len = m.size();
  for (i64 i = 0; i < len; i++) {
    for (i64 j = 0; j < len; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}