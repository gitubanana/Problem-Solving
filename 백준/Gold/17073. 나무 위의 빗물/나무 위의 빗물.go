package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX_V = 500001
	ROOT = 1
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

var (
	vCnt int
	sum, leafCnt float64
	edges = make([][]int, MAX_V)
)

func spreadWater(cur, prev int, water float64) {
	childCnt := len(edges[cur])
	if cur != ROOT {
		childCnt--
	}
	if childCnt == 0 {
		sum += float64(water)
		leafCnt++
		return
	}

	nextWater := water / float64(childCnt)
	for _, next := range edges[cur] {
		if next == prev {
			continue
		}

		spreadWater(next, cur, nextWater)
	}
}

func main() {
	defer writer.Flush()

	var a, b int
	var water float64

	fmt.Fscan(reader, &vCnt, &water)
	for e := 1; e < vCnt; e++ {
		fmt.Fscan(reader, &a, &b)
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}

	spreadWater(ROOT, 0, water)
	fmt.Fprintln(writer, sum / leafCnt)
}
