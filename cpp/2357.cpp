#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int n : nums)
      if (n)
        heap.push(n);
    int ret = 0, x;
    while (heap.size()) {
      x = heap.top();
      heap.pop();
      while (heap.top() == x) {
        heap.pop();
        if (heap.size() == 0)
          break;
      }
      ret++;
    }
    return ret;
  }
};
