class Solution:
    def longestPalindrome(self, words): #: List[str]) -> int:
        dic = dict()
        s = set()
        ret = 0
        for word in words:
            word_in_dic = word in dic
            if word[0] == word[1]:
                if word_in_dic and dic[word] > 0:
                    dic[word] -= 1
                    ret += 4
                    s.remove(word)
                else:
                    dic[word] = 1
                    s.add(word)
            else:
                word_r = word[::-1]
                if word_r in dic and dic[word_r] > 0:
                    dic[word] = 0
                    dic[word_r] -= 1
                    ret += 4
                elif not word_in_dic:
                    dic[word] = 1
                else:
                    dic[word] += 1

        if len(s) > 0:
            ret += 2
        return ret
