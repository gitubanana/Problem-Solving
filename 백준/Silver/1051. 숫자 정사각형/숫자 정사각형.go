package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX_SIZE = 50
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

var ySize, xSize int
var maxSize int = 1
var arr [MAX_SIZE]string

func findSquare() {
	for y := 0; y < ySize; y++ {
		for x := 0; x < xSize; x++ {
			for len := 1; ; len++ {
				if y+len == ySize || x+len == xSize {
					break
				}

				if arr[y][x] == arr[y][x+len] &&
					arr[y][x] == arr[y+len][x] &&
					arr[y][x] == arr[y+len][x+len] {
					maxSize = max(maxSize, (len+1)*(len+1))
				}
			}
		}
	}
}

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &ySize, &xSize)
	for y := 0; y < ySize; y++ {
		fmt.Fscan(reader, &arr[y])
	}

	findSquare()
	fmt.Fprintln(writer, maxSize)
}
