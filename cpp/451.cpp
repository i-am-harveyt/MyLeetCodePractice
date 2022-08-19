#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    priority_queue<pair<int, char>> heap; // structure: [pair<freq, char>]
    unordered_map<char, int> freq;
    for (char c : s)
      freq[c]++;
    for (auto p = freq.begin(); p != freq.end(); p++)
      heap.push({p->second, p->first});

    string ret = "";
    while (heap.size()) {
      for (int i = 0; i < heap.top().first; i++)
        ret += heap.top().second;
      heap.pop();
    }
    return ret;
  }
};
