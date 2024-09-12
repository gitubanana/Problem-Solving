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

	var inputCnt int
	var Q1, Q2, Q3, Q4, AXIS int
	var x, y int

	fmt.Fscan(reader, &inputCnt)
	for ; inputCnt > 0; inputCnt-- {
		fmt.Fscan(reader, &x, &y)

		if x == 0 || y == 0 {
			AXIS++
		} else if y > 0 {
			if x > 0 {
				Q1++
			} else {
				Q2++
			}
		} else {
			if x > 0 {
				Q4++
			} else {
				Q3++
			}
		}
	}

	fmt.Fprintln(writer, "Q1:", Q1)
	fmt.Fprintln(writer, "Q2:", Q2)
	fmt.Fprintln(writer, "Q3:", Q3)
	fmt.Fprintln(writer, "Q4:", Q4)
	fmt.Fprintln(writer, "AXIS:", AXIS)
}
