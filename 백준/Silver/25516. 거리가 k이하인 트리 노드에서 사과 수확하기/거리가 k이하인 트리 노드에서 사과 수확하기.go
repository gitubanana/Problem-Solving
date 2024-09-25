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

const (

    MAX_V = 100000

)

var (

    vCnt, ans, limit int

    edges = make([][]int, MAX_V)

    apple = make([]int, MAX_V)

)

func dfs(cur, prev, curDist int) {

    if curDist > limit {

        return

    }

    ans += apple[cur]

    for _, next := range edges[cur] {

        if next == prev {

            continue

        }

        dfs(next, cur, curDist+1)

    }

}

func main() {

    defer writer.Flush()

    var a, b int

    fmt.Fscan(reader, &vCnt, &limit)

    for e := 1; e < vCnt; e++ {

        fmt.Fscan(reader, &a, &b)

        edges[a] = append(edges[a], b)

        edges[b] = append(edges[b], a)

    }

    for v := 0; v < vCnt; v++ {

        fmt.Fscan(reader, &apple[v])

    }

    dfs(0, -1, 0)

    fmt.Fprintln(writer, ans)

}