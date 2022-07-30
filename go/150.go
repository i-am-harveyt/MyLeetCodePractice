package main

import "strconv"

func evalRPN(tokens []string) int {
	var st []int = make([]int, 0)
	for _, v := range tokens {
		switch v {
		case "+":
			st[len(st)-2] += st[len(st)-1]
			st = st[:len(st)-1]
		case "-":
			st[len(st)-2] -= st[len(st)-1]
			st = st[:len(st)-1]
		case "*":
			st[len(st)-2] *= st[len(st)-1]
			st = st[:len(st)-1]
		case "/":
			st[len(st)-2] /= st[len(st)-1]
			st = st[:len(st)-1]
		default:
			val, _ := strconv.Atoi(v)
			st = append(st, val)

		}
	}
	return st[len(st)-1]
}
