package go

func isAnagram(s string, t string) bool {
	var m = map[byte]int{}
	if len(s) != len(t) {
		return false
	}
	size := len(s)
	for i := 0; i < size; i++ {
		m[s[i]]++
	}
	for i := 0; i < size; i++ {
		m[t[i]]--
	}
	for _, v := range m {
		if v != 0 {
			return false
		}
	}
	return true
}
