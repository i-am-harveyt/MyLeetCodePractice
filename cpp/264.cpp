#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    priority_queue<long, vector<long>, greater<long>> heap;
    unordered_set<long> seen;
    heap.push(1);
    long cur;
    while (n > 1) {
      cur = heap.top();
      heap.pop();
      if (seen.find(cur * 2) == seen.end()) {
        heap.push(cur * 2);
        seen.insert(2);
      }
      if (seen.find(cur * 3) == seen.end()) {
        heap.push(cur * 3);
        seen.insert(cur * 3);
      }
      if (seen.find(cur * 5) == seen.end()) {
        heap.push(cur * 5);
        seen.insert(cur * 5);
      }
      n--;
    }
    return int(heap.top());
  }
};
