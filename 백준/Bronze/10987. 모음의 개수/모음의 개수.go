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

const vowel = "aeiou"

func main() {
	defer writer.Flush()

	var str string	

	fmt.Fscan(reader, &str)

	ans := 0
	size := len(str)
	for i := 0; i < size; i++ {
		isVowel := false
		for j := 0; j < 5; j++ {
			if str[i] == vowel[j] {
				isVowel = true
				break
			}
		}

		if isVowel {
			ans++
		}
	}

	fmt.Fprintln(writer, ans)
}
