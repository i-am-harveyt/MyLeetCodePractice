class Solution(object):
    def isSubsequence(self, s, t) -> bool:
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) == 0:
            return True
        if len(t) < len(s):
            return False
        cnt: int = 0
        for i in t:
            if i == s[cnt]:
                cnt += 1
                if cnt == len(s):
                    return True
        return False
