#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
  int size;
  priority_queue<int> heap;
  KthLargest(int k, vector<int> &nums) {
    size = k;
    for (int i : nums) {
      heap.push(0 - i);
      if (heap.size() > size)
        heap.pop();
    }
  }

  int add(int val) {
    heap.push(0 - val);
    if (heap.size() > size)
        heap.pop();
    return 0 - heap.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
