package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader *bufio.Reader = bufio.NewReader(os.Stdin)
	writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

func main() {
	defer writer.Flush()

	var testCnt int
	var r, e, c int

	fmt.Fscan(reader, &testCnt)
	for ; testCnt > 0; testCnt-- {
		fmt.Fscan(reader, &r, &e, &c)

		r2 := e - c
		if r == r2 {
			fmt.Fprintln(writer, "does not matter")
		} else if r > r2 {
			fmt.Fprintln(writer, "do not advertise")
		} else {
			fmt.Fprintln(writer, "advertise")
		}
	}
}
