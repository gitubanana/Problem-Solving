package main

import (
	"fmt"
)

func main() {
	var k, d, a int

	fmt.Scanf("%d/%d/%d", &k, &d, &a)
	if k + a < d || d == 0 {
		fmt.Println("hasu")
	} else {
		fmt.Println("gosu")
	}
}
