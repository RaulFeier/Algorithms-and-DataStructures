def main():
    arr = [2, 5, 3, 20, 7]

    arr.sort()  # the list needs to be sorted

    l = 0
    r = len(arr) - 1
    x = 2

    while l <= r:
        mid = l + (l - r) / 2

        if arr[mid] == x:
            print("FOUND")
            break

        if arr[mid] < x:
            l = mid + 1

        if arr[mid] > x:
            r = mid - 1


main()

# Time complexity O(log size(arr))
