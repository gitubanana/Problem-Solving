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

	var testCnt, a, b int

	fmt.Fscan(reader, &testCnt)
	for ; testCnt > 0; testCnt-- {
		fmt.Fscan(reader, &a, &b)

		for a != b{
			if a > b {
				a /= 2
			} else {
				b /= 2
			}
		}

		fmt.Fprintln(writer, a * 10)
	}
}
