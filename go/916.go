package main

func getMap(s string) map[byte]int {
	var m map[byte]int = make(map[byte]int)
	for i := range s {
		m[s[i]]++
	}
	return m
}

func wordSubsets(words1 []string, words2 []string) []string {
	var ret []string = make([]string, 0)

	for _, s1 := range words1 {
		m1 := getMap(s1)
		ctn := true
		for _, s2 := range words2 {
			m2 := getMap(s2)
			for k := range m2 {
				if m2[k] > 0 && m2[k]-m1[k] > 0 {
					ctn = false
					break
				} else {
					m2[k] -= m1[k]
				}
			}
			if ctn {
				for k := range m2 {
					if m2[k] > 0 {
						ctn = false
						break
					}
				}
			}
			if !ctn {
				break
			}
		}
		if ctn {
			ret = append(ret, s1)
		}
	}

	return ret
}
