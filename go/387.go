package main

func firstUniqChar(s string) int {
	var m map[rune]int = make(map[rune]int)
	for i, c := range s {
		_, e := m[c]
		if e {
			m[c] = -1
		} else {
			m[c] = i
		}
	}
	var ret int = -1

	for i, c := range s {
		if m[c] != -1 {
			ret = i
			break
		}
	}

	return ret
}
