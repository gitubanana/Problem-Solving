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

	var girl, boy int

	for {
		fmt.Fscan(reader, &girl, &boy)
		if girl == 0 {
			break
		}

		fmt.Fprintln(writer, girl + boy)
	}
}
