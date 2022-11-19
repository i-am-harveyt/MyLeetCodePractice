package main

func root(mp map[int]int, cur int) int {
  if _, e := mp[cur]; !e {
		mp[cur] = -1
    return cur
	}
	if mp[cur] <= -1 {
		return cur
	}
	mp[cur] = root(mp, mp[cur])
	return mp[cur]
}

func validPath(n int, edges [][]int, source int, destination int) bool {
	mp := make(map[int]int, 100)

	for i := 0; i < len(edges); i++ {
		r1 := root(mp, edges[i][0])
		r2 := root(mp, edges[i][1])
		if r1 != r2 {
			if mp[r1] < mp[r2] {
				mp[r1] += mp[r2]
				mp[r2] = r1
			} else {
				mp[r2] += mp[r1]
				mp[r1] = r2
			}
		}
	}

	return root(mp, source) == root(mp, destination)
}
