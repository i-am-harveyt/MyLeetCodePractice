package main

import "math"

func minimumTime(time []int, totalTrips int) int64 {
	var ret, l, r int64 = 0, 0, math.MaxInt64
	for l <= r {
		var cnt int64 = 0
		m := (l + r) >> 1
		for _, v := range time {
			cnt += m / int64(v)
			if cnt > int64(totalTrips) {
				break
			}
		}
		if cnt >= int64(totalTrips) {
			ret = m
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return ret
}
