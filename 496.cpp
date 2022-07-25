class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> mono;
    map<int, int> m;
    mono.push(INT_MAX);
    for (int i = nums2.size() - 1; i >= 0; i--) {
      while (mono.top() < nums2[i])
        mono.pop();
      if (mono.size() == 1)
        m[nums2[i]] = -1;
      else
        m[nums2[i]] = mono.top();
      mono.push(nums2[i]);
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
      ans.push_back(m[nums1[i]]);
    return ans;
  }
};
