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

	var c, k, p int

	fmt.Fscan(reader, &c, &k, &p)
	fmt.Fprintln(writer, k * c * (c + 1) / 2 + p * c * (c + 1) * (2 * c + 1) / 6)
}
