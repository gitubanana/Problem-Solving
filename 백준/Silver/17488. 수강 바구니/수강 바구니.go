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

	var rivalCnt, subCnt int

	fmt.Fscan(reader, &rivalCnt, &subCnt)
	cnt := make([]int, subCnt + 1)
	for i := 1; i <= subCnt; i++ {
		fmt.Fscan(reader, &cnt[i])
	}

	got := make([][]int, rivalCnt)
	for id := 0; id < rivalCnt; id++ {
		got[id] = make([]int, 0, subCnt)
	}

	subQ := make([][]int, subCnt + 1)
	for sub := 1; sub <= subCnt; sub++ {
		subQ[sub] = make([]int, 0, cnt[sub])
	}

	for try := 1; try <= 2; try++ {
		for id := 0; id < rivalCnt; id++ {
			for {
				var sub int

				fmt.Fscan(reader, &sub)
				if sub == -1 {
					break
				}

				cnt[sub]--
				subQ[sub] = append(subQ[sub], id)
			}
		}

		for sub := 1; sub <= subCnt; sub++ {
			if cnt[sub] < 0 {
				continue
			}

			for _, id := range subQ[sub] {
				got[id] = append(got[id], sub)
			}

			subQ[sub] = subQ[sub][:0]
		}
	}

	for id := 0; id < rivalCnt; id++ {
		if len(got[id]) == 0 {
			fmt.Fprintln(writer, "망했어요")
			continue
		}

		sort.Slice(got[id], func(i, j int) bool {
			return got[id][i] < got[id][j]
		})

		for _, v := range got[id] {
			fmt.Fprintf(writer, "%v ", v)
		}
		fmt.Fprintln(writer)
	}
}

