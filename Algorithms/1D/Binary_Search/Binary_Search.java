class BinartSearch {
  public static void main() {
    int arr[] = {1, 2, 3, 4, 5, 6};

    int r = arr.length - 1;
    int l = 0;
    int x = 4; // we search for x

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (arr[mid] == x) {
        System.out.println("Found");
        break;
      }

      if (arr[mid] < x) {
        l = mid + 1;
      }

      if (arr[mid] > x) {
        r = mid - 1;
      }
    }
  }
}

// time complexity O(log size(arr))