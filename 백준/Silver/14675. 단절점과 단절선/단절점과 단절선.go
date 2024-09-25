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

func main() {
	defer writer.Flush()

	var vCnt int
	var a, b int

	fmt.Fscan(reader, &vCnt)
	linkCnt := make([]int, vCnt + 1)
	for e := 1; e < vCnt; e++ {
		fmt.Fscan(reader, &a, &b)
		linkCnt[a]++
		linkCnt[b]++
	}

	var qCnt int
	var qType, check int

	fmt.Fscan(reader, &qCnt)
	for ; qCnt > 0; qCnt-- {
		fmt.Fscan(reader, &qType, &check)
		switch qType {
		case 1:
			if linkCnt[check] == 1 {
				fmt.Fprintln(writer, "no")
			} else {
				fmt.Fprintln(writer, "yes")
			}
		default:
			fmt.Fprintln(writer, "yes")
		}
	}
}
