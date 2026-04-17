package main

import (
	"fmt"
)

func main() {
	var waveLength int

	fmt.Scan(&waveLength)
	if waveLength >= 620 {
		fmt.Println("Red")
	} else if waveLength >= 590 {
		fmt.Println("Orange")
	} else if waveLength >= 570 {
		fmt.Println("Yellow")
	} else if waveLength >= 495 {
		fmt.Println("Green")
	} else if waveLength >= 450 {
		fmt.Println("Blue")
	} else if waveLength >= 425 {
		fmt.Println("Indigo")
	} else {
		fmt.Println("Violet")
	}
}
