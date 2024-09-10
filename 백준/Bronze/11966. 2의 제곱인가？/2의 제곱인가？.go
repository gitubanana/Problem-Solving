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

	fmt.Fscan(reader, &num)
	for ; num & 1 == 0; num >>= 1{
	}

	if num == 1 {
		fmt.Fprintln(writer, "1")
	} else {
		fmt.Fprintln(writer, "0")
	}
}
