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

	var strCnt, qCnt int

	fmt.Fscan(reader, &strCnt, &qCnt)
	strs := make([]string, strCnt)
	for i := 0; i < strCnt; i++ {
		fmt.Fscan(reader, &strs[i])
	}

	sort.Slice(strs, func(i, j int) bool {
		return strs[i] > strs[j]
	})

	var toFind string

	ans := 0
	for ; qCnt > 0; qCnt-- {
		fmt.Fscan(reader, &toFind)

		for _, cmp := range strs {
			if len(cmp) >= len(toFind) {
				if cmp[:len(toFind)] == toFind {
					ans++
					break
				} else if cmp[:len(toFind)] < toFind {
					break
				}
			}
		}
	}

	fmt.Fprintln(writer, ans)
}
