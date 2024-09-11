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

	var chant string

	fmt.Fscan(reader, &chant)
	switch chant {
	case "SONGDO":
		fmt.Fprintln(writer, "HIGHSCHOOL")
	case "CODE":
		fmt.Fprintln(writer, "MASTER")
	case "2023":
		fmt.Fprintln(writer, "0611")
	case "ALGORITHM":
		fmt.Fprintln(writer, "CONTEST")
	}
}
