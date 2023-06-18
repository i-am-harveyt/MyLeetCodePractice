class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ret, l, r = 0, -1, 1
        seen = set()
        while r < len(s):
            while s[r] in seen:
                l += 1
                seen.remove(s)
        return ret
