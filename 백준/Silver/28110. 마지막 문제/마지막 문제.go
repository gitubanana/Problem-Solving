package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

func main() {
	defer writer.Flush()

	var size int

	fmt.Fscan(reader, &size)
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	ans := -1
	maxDiff := 0
	for i := 1; i < size; i++ {
		mid := (arr[i - 1] + arr[i]) / 2
		if mid == arr[i - 1] {
			continue
		}

		curDiff := min(mid - arr[i - 1], arr[i] - mid)
		if maxDiff >= curDiff {
			continue
		}

		maxDiff = curDiff
		ans = mid
	}

	fmt.Fprintln(writer, ans)
}
