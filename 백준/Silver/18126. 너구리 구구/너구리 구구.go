package main

import (

    "fmt"

    "os"

    "bufio"

)

var (

    reader = bufio.NewReader(os.Stdin)

    writer = bufio.NewWriter(os.Stdout)

)

type t_edge struct {

    weight int64

    v int

}

const (

    MAX_V = 5001

)

var (

    vCnt int

    maxDist int64

    edges = make([][]t_edge, MAX_V)

)

func dfs(cur, prev int, curDist int64) {

    if maxDist < curDist {

        maxDist = curDist

    }

    for _, next := range edges[cur] {

        if next.v == prev {

            continue

        }

        dfs(next.v, cur, curDist+next.weight)

    }

}

func main() {

    defer writer.Flush()

    var a, b int

    var w int64

    fmt.Fscan(reader, &vCnt)

    for e := 1; e < vCnt; e++ {

        fmt.Fscan(reader, &a, &b, &w)

        edges[a] = append(edges[a], t_edge{w, b})

        edges[b] = append(edges[b], t_edge{w, a})

    }

    dfs(1, 0, 0)

    fmt.Fprintln(writer, maxDist)

}