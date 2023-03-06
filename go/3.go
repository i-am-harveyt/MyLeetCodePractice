package main

func lengthOfLongestSubstring(s string) int {
	ret, idx := 0, 0

	set := make(map[byte]int)

	for i := 0; i < len(s); i++ {
		_, ok := set[s[i]]
		if ok {
			for _, oki := set[s[i]]; oki; {
				delete(set, s[idx])
				idx++
				_, oki = set[s[i]]
			}
			set[s[i]] = 1
		} else {
			set[s[i]] = 1
			if i-idx+1 > ret {
				ret = i - idx + 1
			}
		}
	}

	return ret
}
