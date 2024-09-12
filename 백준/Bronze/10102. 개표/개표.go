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

	var size int
	var votes string
	var aCnt, bCnt int

	fmt.Fscan(reader, &size, &votes)
	for i := 0; i < size; i++ {
		switch votes[i] {
		case 'A':
			aCnt++
		case 'B':
			bCnt++
		}
	}

	switch {
	case aCnt == bCnt:
		fmt.Fprintln(writer, "Tie")
	case aCnt > bCnt:
		fmt.Fprintln(writer, "A")
	default:
		fmt.Fprintln(writer, "B")
	}
}
