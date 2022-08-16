#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int fillCups(vector<int> &amount) {
    priority_queue<int> heap;
    for (int n : amount)
      if (n)
        heap.push(n);
    int ret = 0;
    while (heap.size() > 0) {
      ret++;
      int x = heap.top();
      heap.pop();
      x--;
      if (heap.size() > 0) {
        int y = heap.top();
        heap.pop();
        y--;
        if (y)
          heap.push(y);
      } else {
        ret += x;
        break;
      }
      if (x)
        heap.push(x);
    }
    return ret;
  }
};
