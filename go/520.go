package main

func detectCapitalUse(word string) bool {
	cnt := 0
	for _, c := range word {
		if c >= 'A' && c <= 'Z' {
			cnt++
		}
	}
	return cnt == len(word) || cnt == 0 || (cnt == 1 && word[0] >= 'A' && word[0] <= 'Z')
}
