from typing import List


class Solution:
    def insert(self, intervals: List[List[int]],
               newInterval: List[int]) -> List[List[int]]:
        # handle if no interval is given
        if len(intervals) == 0:
            return [newInterval]
        # condition1: if new interval lesser than all given intervals
        if newInterval[1] < intervals[0][0]:
            return [newInterval] + intervals
        # condition2: if new interval greater than all given intervals
        if newInterval[0] > intervals[-1][1]:
            return intervals + [newInterval]

        # condition3: between
        # find place
        st, ed = 0, len(intervals)-1
        while st < len(intervals) and newInterval[0] > intervals[st][1]:
            st += 1
        while ed > -1 and newInterval[1] < intervals[ed][0]:
            ed -= 1

        # change boundary
        if newInterval[0] > intervals[st][0]:
            newInterval[0] = intervals[st][0]
        if newInterval[1] < intervals[ed][1]:
            newInterval[1] = intervals[ed][1]

        # consititude return List
        ret: List[List[int]] = []
        ret += intervals[:st]
        ret += [newInterval]
        ret += intervals[ed+1:]
        return ret
