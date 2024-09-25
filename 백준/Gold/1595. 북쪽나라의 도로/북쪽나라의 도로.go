package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX_V = 10001
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

type t_edge struct {
	v, weight int
}

var (
	edges = make([][]t_edge, MAX_V)
	maxDist, maxV int
)

func dfs(cur, prev, curDist int) {
	if maxDist < curDist {
		maxDist = curDist
		maxV = cur
	}

	for _, next := range edges[cur] {
		if next.v == prev {
			continue
		}

		dfs(next.v, cur, curDist + next.weight)
	}
}

func main() {
	defer writer.Flush()

	var a, b, weight int

	for {
		_, err := fmt.Fscan(reader, &a, &b, &weight)
		if err != nil {
			break
		}

		edges[a] = append(edges[a], t_edge{b, weight})
		edges[b] = append(edges[b], t_edge{a, weight})
	}

	dfs(a, 0, 0)
	maxDist = 0
	dfs(maxV, 0, 0)
	fmt.Fprintln(writer, maxDist)
}
