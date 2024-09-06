package main

import (
	"fmt"
)

func main() {
	var testCnt int

	fmt.Scan(&testCnt)
	for t := 1; t <= testCnt; t++ {
		var peopleCnt int
		m := make(map[int]int)

		fmt.Scan(&peopleCnt)
		for ; peopleCnt > 0; peopleCnt-- {
			var id int

			fmt.Scan(&id)
			m[id]++
		}

		for id, value := range m {
			if value == 1 {
				fmt.Printf("Case #%d: %d\n", t, id)
				break
			}
		}
	}
}
