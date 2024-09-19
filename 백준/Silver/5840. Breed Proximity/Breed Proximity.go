package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

const (
	MAX_ID = 1000000
)

func main() {
	defer writer.Flush()

	var cowCnt, dist, id int

	fmt.Fscan(reader, &cowCnt, &dist)

	maxCrowdedId := -1
	recentOrder := make([]int, MAX_ID + 1)
	for curOrder := 1; curOrder <= cowCnt; curOrder++ {
		fmt.Fscan(reader, &id)

		if recentOrder[id] != 0 {
			if curOrder - recentOrder[id] <= dist {
				maxCrowdedId = max(maxCrowdedId, id)
			}
		}

		recentOrder[id] = curOrder
	}

	fmt.Fprintln(writer, maxCrowdedId)
}
