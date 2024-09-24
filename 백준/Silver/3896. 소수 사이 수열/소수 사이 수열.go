package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX_SIZE = 1299709 + 1
	MAX_PRIME_TH = 100000
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

var isNotPrime [MAX_SIZE]bool
var primeNum = make([]int, 0, MAX_PRIME_TH)

func getBetweenLen(toFind int) int {
	var lastMid int

	left := 0
	right := len(primeNum) - 1

	for ; left <= right; {
		mid := (left + right) / 2
		cmp := primeNum[mid]

		lastMid = mid
		switch {
		case cmp == toFind:
			return 0
		case cmp > toFind:
			right = mid - 1
		default:
			left = mid + 1
		}
	}

	cmp := primeNum[lastMid]
	if cmp > toFind {
		return cmp - primeNum[lastMid - 1]
	}

	return primeNum[lastMid + 1] - cmp
}

func main() {
	defer writer.Flush()

	for mul := 2; mul < MAX_SIZE; mul++ {
		if isNotPrime[mul] {
			continue
		}

		primeNum = append(primeNum, mul)
		for num := mul * 2; num < MAX_SIZE; num += mul {
			isNotPrime[num] = true
		}
	}

	var testCnt, toFind int

	fmt.Fscan(reader, &testCnt)
	for ; testCnt > 0; testCnt-- {
		fmt.Fscan(reader, &toFind)
		fmt.Fprintln(writer, getBetweenLen(toFind))
	}
}
