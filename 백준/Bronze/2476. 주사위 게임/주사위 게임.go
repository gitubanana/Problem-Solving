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

	var rollCnt int
	var a, b, c int
	var maxMoney int

	fmt.Fscan(reader, &rollCnt)
	for ; rollCnt > 0; rollCnt-- {
		fmt.Fscan(reader, &a, &b, &c)

		if a == b && b == c {
			maxMoney = max(maxMoney, 10000 + a * 1000)
		} else if a == b {
			maxMoney = max(maxMoney, 1000 + a * 100)
		} else if b == c {
			maxMoney = max(maxMoney, 1000 + b * 100)
		} else if c == a {
			maxMoney = max(maxMoney, 1000 + c * 100)
		} else {
			maxMoney = max(maxMoney, max(a, b, c) * 100)
		}
	}

	fmt.Fprintln(writer, maxMoney)
}
