package main

import (
  "fmt"
  "strings"
)

func main() {
  var ySize, xSize int

  fmt.Scan(&ySize, &xSize)

  line := strings.Repeat("*", xSize)
  for y := 0; y < ySize; y++ {
    fmt.Println(line)
  }
}
