#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> mono;
        int size = height.size(), ret = 0, dist, lt, minHeight;
        for (int i = 0; i < size ; i++) {
            while (!mono.empty() && height[i] > height[mono.top()]) {
                lt = mono.top();
                mono.pop();
                if (mono.empty())
                    break;
                minHeight = min(height[i], height[mono.top()]);
                dist = minHeight - height[lt];
                ret += dist * (i - mono.top() - 1);
            }
            mono.push(i);
        }
        return ret;
    }
};
