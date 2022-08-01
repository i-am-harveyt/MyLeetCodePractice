class Solution {
public:
    int fac(int n) {
        if (n == 0)
            return 1;
        int res = 1;
        for (int i = 2 ; i <= n ; i++)
            res *= i;
            return res;
    }

    int uniquePaths(int m, int n) {
        return fac(m+n-2) / (fac(n-1)*fac(m-1));
    }
};