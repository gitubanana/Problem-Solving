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

	var prev, cur int

	fmt.Fscan(reader, &prev)
	for {
		_, error := fmt.Fscan(reader, &cur)
		if error != nil {
			break
		}

		if prev > cur{
			fmt.Fprintln(writer, "Bad")
			return
		}
		prev = cur
	}

	fmt.Fprintln(writer, "Good")
}
