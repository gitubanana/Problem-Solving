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

func parseTime(str string) int {
	hour, _ := strconv.Atoi(str[:2])
	minute, _ := strconv.Atoi(str[3:])
	return hour * 60 + minute
}

func main() {
	defer writer.Flush()

	var start, mid, end string

	fmt.Fscan(reader, &start, &mid, &end)
	var (
		startTime = parseTime(start)
		midTime = parseTime(mid)
		endTime = parseTime(end)
	)
	var strTime, name string

	ans := 0
	m := make(map[string]bool)
	for {
		_, err := fmt.Fscan(reader, &strTime, &name)
		if err != nil {
			break
		}

		curTime := parseTime(strTime)
		switch {
		case curTime <= startTime:
			m[name] = true
		case midTime <= curTime && curTime <= endTime:
			if m[name] {
				m[name] = false
				ans++
			}
		}
	}

	fmt.Fprintln(writer, ans)
}
