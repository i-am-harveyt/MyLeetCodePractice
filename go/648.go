package main

import (
	"strings"
)

func replaceWords(dictionary []string, sentence string) string {
	tokens := strings.Split(sentence, " ")

	ret := ""

	for i := 0; i < len(tokens); i++ {
		for j := 0; j < len(dictionary); j++ {
			if strings.HasPrefix(tokens[i], dictionary[j]) {
				tokens[i] = dictionary[j]
			}
		}
		if len(ret) != 0 {
			ret += " "
		}
		ret += tokens[i]
	}

	return ret
}
