from string import printable


class Solution(object):
    def convert(self, s) -> str:
        seen: dict[str, str] = dict()
        cnt: int = -1
        ret: str = ""
        for i in range(len(s)):
            if s[i] in seen:
                ret += seen[s[i]]
            else:
                cnt += 1
                ret += printable[cnt]
                seen[s[i]] = printable[cnt]
        del seen
        return ret

    def isIsomorphic(self, s, t) -> bool:
        if len(s) != len(t):
            return False
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s = self.convert(s)
        t = self.convert(t)
        print(s, t)
        if s != t:
            return False

        return True
