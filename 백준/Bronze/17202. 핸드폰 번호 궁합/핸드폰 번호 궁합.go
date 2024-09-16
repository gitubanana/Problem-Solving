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

	var a, b string

	fmt.Fscan(reader, &a, &b)

	arr := make([]int, len(a) + len(b))
	for i := 0; i < len(a); i++ {
		arr[i * 2] = int(a[i] - '0')
		arr[i * 2 + 1] = int(b[i] - '0') 
	}
	for {
		size := len(arr)
		if size == 2 {
			break
		}

		newArr := make([]int, size - 1)
		for i := 1; i < size; i++ {
			newArr[i - 1] = (arr[i - 1] + arr[i]) % 10
		}

		arr = newArr
	}

	fmt.Fprintf(writer, "%d%d\n", arr[0], arr[1])
}
