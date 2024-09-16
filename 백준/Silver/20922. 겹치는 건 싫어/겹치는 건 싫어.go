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

	var size, sameCnt int

	fmt.Fscan(reader, &size, &sameCnt)
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	var ans, left, right int
	cnt := make(map[int]int) 

	for left <= right && right < size {
		if cnt[arr[right]] < sameCnt {		
			cnt[arr[right]]++
			right++
		} else {
			cnt[arr[left]]--
			left++
		}

		ans = max(ans, right - left)
	}

	fmt.Fprintln(writer, ans)
}
