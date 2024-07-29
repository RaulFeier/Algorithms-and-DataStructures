#include "../../../../HEADER.h"

const i64 MAX_N = 450; // if N is > 450 we cant use Floyd Warshall 

i64 AM[MAX_N][MAX_N]; // it is better to store a bigger array in the heap

int main() {
  i64 n, e;
  cin >> n >> e;
  

  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < n;j++) {
      AM[i][j] = INF; 
    }
    AM[i][i] = 0;
  }

  for (i64 i = 0; i < e; i++) {
    i64 a, b, w;
    cin >> a >> b >> w;
    AM[a][b] = w;
  }

  for (i64 k = 0; k < n; k++) {
    for (i64 i = 0; i < n;i++) {
      for (i64 j = 0; j < n; j++) {
        AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
      }
    }
  }

  return 0;
}
