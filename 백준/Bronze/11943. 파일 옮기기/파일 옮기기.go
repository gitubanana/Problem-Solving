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

	var aApple, aOrange int
	var bApple, bOrange int

	fmt.Fscan(reader, &aApple, &aOrange)
	fmt.Fscan(reader, &bApple, &bOrange)
	fmt.Fprintln(writer, min(aApple + bOrange, bApple + aOrange))
}
