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
	
	fmt.Fscan(reader, &testCnt)
	for ; testCnt > 0; testCnt-- {
		var num string
		var lastNum int

		fmt.Fscan(reader, &num)
		lastNum = int(num[len(num) - 1] - '0')

		if lastNum & 1 == 1 {
			fmt.Fprintln(writer, "odd")
		} else {
			fmt.Fprintln(writer, "even")
		}
	}
}
