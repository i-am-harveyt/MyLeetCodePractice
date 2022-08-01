#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<vector<int>> c(26, vector<int>(2, 0));
        for (int i = 0; i < s.size(); i++)
        {
            c[s[i] - 'a'][0] = i;
            c[s[i] - 'a'][1]++;
        }
        int ret = s.size();
        for (int i = 0; i < 26; i++)
        {
            if (c[i][1] == 1 && c[i][0] < ret)
                ret = c[i][0];
        }
        if (ret == s.size())
            return -1;
        return ret;
    }
};