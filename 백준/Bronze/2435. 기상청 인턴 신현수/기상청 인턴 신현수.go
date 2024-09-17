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

	var arrSize, windowSize int

	fmt.Fscan(reader, &arrSize, &windowSize)
	arr := make([]int, arrSize)
	for i := 0; i < arrSize; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	curTemp := 0
	for i := 0; i < windowSize; i++ {
		curTemp += arr[i]
	}

	maxTemp := curTemp
	for i := windowSize; i < arrSize; i++ {
		curTemp -= arr[i - windowSize]
		curTemp += arr[i]

		maxTemp = max(maxTemp, curTemp)
	}

	fmt.Fprintln(writer, maxTemp)
}
