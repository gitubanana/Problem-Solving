package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	reader *bufio.Reader = bufio.NewReader(os.Stdin)
	writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

func main() {
	defer writer.Flush()

	var totalStr, plus string

	for {
		_, err := fmt.Fscan(reader, &plus)
		if err != nil {
			break ;
		}
		totalStr += plus
	}

	var sum, s int

	for e, ch := range totalStr {
		if ch == ','  {
			num, _ := strconv.Atoi(totalStr[s:e])
			sum += num
			s = e + 1
		}
	}

	num, _ := strconv.Atoi(totalStr[s:len(totalStr)])
	fmt.Fprintln(writer, sum + num)
}
