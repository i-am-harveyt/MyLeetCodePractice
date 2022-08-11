package main

import "strings"

func isValidSerialization(preorder string) bool {
  var ret = 1
  tokens := strings.Split(preorder, ",")
  for _, v := range tokens {
    ret--
    if ret < 0 {
      return false
    }
    if v != "#" {
      ret += 2
    }
  }
  return ret == 0
}
