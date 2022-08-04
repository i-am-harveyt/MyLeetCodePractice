class Solution {
public:
  long nCm(int n, int m) {
    long ret = 1;
    for (int i = 0; i < m; i++) {
      ret *= (n - i);
      ret /= (i + 1);
    }
    return ret;
  }
  int numTrees(int n) { return nCm((2 * n), n) / (n + 1); }
};
