#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &score) {
    priority_queue<int> heap;
    for (int n : score) // use heap to help sorting
      heap.push(n);
    unordered_map<int, string> map; // get mapping: score->rank
    if (score.size() >= 1) {
      map[heap.top()] = "Gold Medal";
      heap.pop();
    }
    if (score.size() >= 2) {
      map[heap.top()] = "Silver Medal";
      heap.pop();
    }
    if (score.size() >= 3) {
      map[heap.top()] = "Bronze Medal";
      heap.pop();
    }
    for (int i = 4; i <= score.size(); i++) {
      map[heap.top()] = to_string(i);
      heap.pop();
    }
    vector<string> ret;
    for (int i = 0; i < score.size(); i++)
      ret.push_back(map[score[i]]);
    return ret;
  }
};
