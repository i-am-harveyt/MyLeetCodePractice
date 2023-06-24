#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> ret;
    if (intervals.size() == 0) {
      ret.push_back(newInterval);
      return ret;
    }
    // find start index
    size_t st = 0;
    while (st < intervals.size() && newInterval[0] > intervals[st][1])
      ++st;

    // find end index
    size_t ed = intervals.size() - 1;
    while (ed > -1 && newInterval[1] < intervals[ed][0])
      --ed;

    // condition1: st == intervals.size()
    if (st == intervals.size()) {
      for (size_t i = 0; i < intervals.size(); i++)
        ret.push_back(intervals[i]);
      ret.push_back(newInterval);
      return ret;
    }

    // condition2: ed == -1
    if (ed == -1) {
      ret.push_back(newInterval);
      for (size_t i = 0; i < intervals.size(); i++)
        ret.push_back(intervals[i]);
      return ret;
    }

    // condition3: between
    // insert interval
    vector<int> insert(2, 0);
    insert[0] =
        newInterval[0] < intervals[st][0] ? newInterval[0] : intervals[st][0];
    insert[1] =
        newInterval[1] > intervals[ed][1] ? newInterval[1] : intervals[ed][1];

    // insert
    // vector<vector<int>> ret;
    for (size_t i = 0; i < st; i++)
      ret.push_back(intervals[i]);
    ret.push_back(insert);
    for (size_t i = ed + 1; i < intervals.size(); i++)
      ret.push_back(intervals[i]);

    return ret;
  }
};
