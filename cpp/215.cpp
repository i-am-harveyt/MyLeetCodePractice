#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> maxheap;
    for (int n : nums)
        maxheap.push(n);
    while (k > 1) { // pop 1st to k-1th largest
        maxheap.pop();
        k--;
    }
    return maxheap.top();
  }
};
