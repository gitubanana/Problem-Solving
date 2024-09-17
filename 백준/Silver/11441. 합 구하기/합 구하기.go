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

	var size, num int

	fmt.Fscan(reader, &size)
	prefixSum := make([]int, size + 1)
	for i := 1; i <= size; i++ {
		fmt.Fscan(reader, &num)
		prefixSum[i] = prefixSum[i - 1] + num
	}

	var qCnt int
	var start, end int

	fmt.Fscan(reader, &qCnt)
	for ; qCnt > 0; qCnt-- {
		fmt.Fscan(reader, &start, &end)
		fmt.Fprintln(writer, prefixSum[end] - prefixSum[start - 1])
	}
}
