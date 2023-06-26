from typing import List


class MinStack:

    def __init__(self):
        self.st: List = []
        self.m: int = 2**31-1

    def push(self, val: int) -> None:
        self.st.append(self.m)
        self.st.append(val)
        self.m = min(self.m, val)

    def pop(self) -> None:
        self.st.pop(-1)
        self.m = self.st[-1]
        self.st.pop(-1)

    def top(self) -> int:
        return self.st[-1]

    def getMin(self) -> int:
        return self.m


# Your MinStack object will be instantiated and called as such:
# obj = inStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
