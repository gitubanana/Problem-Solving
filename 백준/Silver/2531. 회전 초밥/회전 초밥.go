package main

import (
	"fmt"
	"os"
	"bufio"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

func getTypeCnt(tCnt []int) (typeCnt int) {
	for t := 1; t < len(tCnt); t++ {
		if tCnt[t] > 0 {
			typeCnt++
		}
	}
	return
}

func main() {
	defer writer.Flush()

	var arrSize, typeCnt, windowSize, coupon int

	fmt.Fscan(reader, &arrSize, &typeCnt, &windowSize, &coupon)
	arr := make([]int, arrSize)
	for i := 0; i < arrSize; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	tCnt := make([]int, typeCnt + 1)
	for i := 0; i < windowSize; i++ {
		tCnt[arr[i]]++
	}
	tCnt[coupon]++

	maxType := getTypeCnt(tCnt)
	prev := 0
	for {
		cur := (prev + windowSize) % arrSize

		tCnt[arr[prev]]--
		tCnt[arr[cur]]++
		maxType = max(maxType, getTypeCnt(tCnt))

		if cur == windowSize - 2 {
			break
		}
		prev++
	}

	fmt.Fprintln(writer, maxType)
}
