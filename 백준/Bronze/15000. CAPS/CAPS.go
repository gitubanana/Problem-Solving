package main

import (
	"strings"
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

	var msg string

	fmt.Fscan(reader, &msg)
	fmt.Fprintln(writer, strings.ToUpper(msg))
}
