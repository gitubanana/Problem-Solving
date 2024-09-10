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

	var num int64
	var squareOfTwo = 0

	fmt.Fscan(reader, &num)
	for cmp := int64(1); ; cmp <<= 1 {
		if cmp > num {
			break
		}

		if cmp == num {
			squareOfTwo = 1
			break
		}
	}

	fmt.Fprintln(writer, squareOfTwo)
}
