import (
	"math"
	"sort"
)

func helper(mem *map[[2]int]int, arr1, arr2 *[]int, idx, prev int) int {
	if idx == len(*arr1) {
		return 0
	}
	if v, found := (*mem)[[2]int{idx, prev}]; found {
		return v
	}

	change, notchange := 1000*1000*1000, 1000*1000*1000
	/* not change */
	if (*arr1)[idx] > prev {
		change = helper(mem, arr1, arr2, idx+1, (*arr1)[idx])
	}
	/* change */
	i := sort.Search(len(*arr2), func(i int) bool {
		return (*arr2)[i] > prev
	})
	if i != len(*arr2) {
		notchange = 1 + helper(mem, arr1, arr2, idx+1, (*arr2)[i])
	}
	(*mem)[[2]int{idx, prev}] = int(math.Min(float64(change), float64(notchange)))
	return (*mem)[[2]int{idx, prev}]
}

func makeArrayIncreasing(arr1 []int, arr2 []int) int {
	mem := make(map[[2]int]int, 0)
	sort.Slice(arr2, func(i, j int) bool {
		return arr2[i] < arr2[j]
	})
	ret := helper(&mem, &arr1, &arr2, 0, -1)
	if ret == 1e9 {
		return -1
	}
	return ret
}
