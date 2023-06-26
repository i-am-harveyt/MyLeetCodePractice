from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for s in tokens:
            if s == '+':
                st[-2] += st[-1]
                st = st[:-1]
            elif s == '-':
                st[-2] -= st[-1]
                st = st[:-1]
            elif s == '*':
                st[-2] *= st[-1]
                st = st[:-1]
            elif s == '/':
                st[-2] = st[-2] // st[-1]
                st = st[:-1]
            else:
                st.append(int(s))

        return st[0]
