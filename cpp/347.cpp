#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;
    unordered_map<int, 
      int> m;

    for (int n : nums) // to get m[num] = count
      m[n]++;

    // put data in map into heap to sort it and controll size as well
    for (auto p = m.begin(); p != m.end(); p++){
      heap.push({p->second, p->first});
      if (heap.size() > k)
        heap.pop();
    }

    // get ret
    vector<int> ret;
    while (heap.size() > 0) {
      ret.push_back(heap.top().second);
      heap.pop();
    }
    return ret;
  }
};
