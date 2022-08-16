#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int ret = 0;
    priority_queue<int> heap;
    for (int n : nums) {
      heap.push(n);
    }
    int x = heap.top();
    heap.pop();
    int y = heap.top();
    return (x-1)*(y-1);
  }
};
