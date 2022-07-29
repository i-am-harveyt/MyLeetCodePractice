package main

func findAndReplacePattern(words []string, p string) []string {
	s2p, p2s := make(map[byte]byte, 0), make(map[byte]byte, 0)
	size := len(p) // p stands for pattern
	i := 0         // for index
	ret := make([]string, 0)
	for _, s := range words {
		for i = 0; i < size; i++ {
			pv, ep := p2s[p[i]]
			sv, es := s2p[s[i]]
			if !ep && !es {
				p2s[p[i]] = s[i]
				s2p[s[i]] = p[i]
				continue
			}
			if pv != s[i] || sv != p[i] {
				break
			}

		}
		if i == size {
			ret = append(ret, s)
		}
		// clear maps
		for k := range s2p {
			delete(s2p, k)
		}
		for k := range p2s {
			delete(p2s, k)
		}

	}
	return ret
}
