/*
Median of Two Sorted Arrays

There are two sorted arrays A and B of size m and n respectively. Find the
median of the two sorted arrays. The overall run time complexity should be O(log
(m+n)).
*/

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) % 2 != 0) {
      return findKth(A, m, B, n, (m + n) / 2 + 1);
    } else {
      return (findKth(A, m, B, n, (m + n) / 2) +
              findKth(A, m, B, n, (m + n) / 2 + 1)) /
             2.0;
    }
  }

  int findKth(int a[], int m, int b[], int n, int k) {
    int i = findKthHelper(a, m, b, n, k);
    return i < 0 ? b[findKthHelper(b, n, a, m, k)] : a[i];
  }

  int findKthHelper(int a[], int m, int b[], int n, int k) { // k = 1, 2, ...
    int low = 0, high = m - 1, mid = 0;
    while (low <= high) {
      mid = (low + high) / 2;
      if (mid + 1 + n < k) {
        low = mid + 1;
        continue;
      }
      if (mid + 1 > k) {
        high = mid - 1;
        continue;
      }
      int pre = k - mid - 2 >= 0 ? b[k - mid - 2] : a[mid];
      int post = k - mid - 1 < n ? b[k - mid - 1] : a[mid];
      if (pre <= a[mid] && a[mid] <= post) {
        return mid;
      } else if (a[mid] > post) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }
};
