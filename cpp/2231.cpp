#include <functional>
#include <queue>

using namespace std;

class Solution {
public:
  int largestInteger(int num) {
    // min heap
    priority_queue<int, vector<int>, greater<int>> oddheap, evenheap;
    // record all nums and categorize them
    int tmp = num, cur;
    while (tmp > 0) {
      cur = tmp % 10;
      if (cur % 2)
        oddheap.push(cur);
      else
        evenheap.push(cur);
      tmp /= 10;
    }

    // add them back to ret
    int ret = 0, weight = 1;
    while (true) {
      cur = num % 10;
      if (cur % 2) {
        ret += oddheap.top() * weight;
        oddheap.pop();
      } else {
        ret += evenheap.top() * weight;
        evenheap.pop();
      }
      num /= 10;
      if (num > 0)
        weight *= 10;
      else
        break;
    }
    return ret;
  }
};
