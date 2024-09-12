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

	var sec int

	fmt.Fscan(reader, &sec)

	var A = sec / 300
	var B = (sec - A * 300) / 60
	var C = (sec - A * 300 - B * 60) / 10

	if sec % 10 != 0 {
		fmt.Fprintln(writer, "-1")
	} else {
		fmt.Fprintln(writer, A, B, C)
	}
}
