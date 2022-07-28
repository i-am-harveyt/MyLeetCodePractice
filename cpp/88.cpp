#include <iostream>
#include <vector>

using namespace std;

// my way
class Solution1 {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

    if (n == 0)
      return;

    vector<int> v = vector<int>(m + n, INT_MAX);
    int i = 0, j = 0, k = 0;
    while (j < m && k < n) {
      if (nums1[j] <= nums2[k])
        v[i++] = nums1[j++];
      else
        v[i++] = nums2[k++];
    }

    while (j < m)
      v[i++] = nums1[j++];
    while (k < n)
      v[i++] = nums2[k++];

    for (i = 0; i < m + n; i++)
      nums1[i] = v[i];
  }
};

// speed up way
class Solution2 {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = m + n - 1;
    int t1 = m - 1, t2 = n - 1;

    while (t1 >= 0 && t2 >= 0)
      if (nums1[t1] >= nums2[t2])
        nums1[t--] = nums1[t1--];
      else
        nums1[t--] = nums2[t2--];

    while (t1 >= 0)
      nums1[t--] = nums1[t1--];
    while (t2 >= 0)
      nums1[t--] = nums2[t2--];
  }
};
