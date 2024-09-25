package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX_V = 200001
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

type t_edge struct {
	v, weight int
}

var (
	vCnt, root int
	dist       [2]int
	edges      = make([][]t_edge, MAX_V)
)

func dfs(cur, prev, curDist, cmpIdx int) {
	dist[cmpIdx] = max(dist[cmpIdx], curDist)

	childCnt := len(edges[cur])
	if cur != root {
		childCnt--
	}
	if cmpIdx == 0 && childCnt >= 2 {
		cmpIdx = 1
		curDist = 0
	}

	for _, next := range edges[cur] {
		if next.v == prev {
			continue
		}

		dfs(next.v, cur, curDist+next.weight, cmpIdx)
	}
}

func main() {
	defer writer.Flush()

	var a, b, weight int

	fmt.Fscan(reader, &vCnt, &root)
	for e := 1; e < vCnt; e++ {
		fmt.Fscan(reader, &a, &b, &weight)

		edges[a] = append(edges[a], t_edge{b, weight})
		edges[b] = append(edges[b], t_edge{a, weight})
	}

	dfs(root, 0, 0, 0)
	fmt.Fprintln(writer, dist[0], dist[1])
}
