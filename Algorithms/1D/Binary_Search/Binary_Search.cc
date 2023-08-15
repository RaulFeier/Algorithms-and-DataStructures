#include "../../../HEADER.h"

int main() {
  i64 n;
  cin >> n;

  vi64 arr(n);
  for (i64 i : range(n)) {
    cin >> arr[i];
  }

  // vector needs to be sorted before binary search

  srt(arr);

  i64 l = 0;
  i64 r = n - 1;
  i64 x = 3; // we search for x

  while (l <= r) {
    i64 mid = l + (r - l) / 2;

    if (arr[mid] == x) {
      cout << "Found" << endl;
      break;
    }

    if (arr[mid] < x) {
      l = mid + 1;
    }

    if (arr[mid] > x) {
      r = mid - 1;
    }
  }

  return 0;
}

// time complexity O(log size(arr))