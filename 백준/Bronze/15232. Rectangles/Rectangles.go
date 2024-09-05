package main

import (
  "fmt"
)

func main() {
  var ySize, xSize int

  fmt.Scan(&ySize, &xSize)
  for y := 0; y < ySize; y++ {
    for x := 0; x < xSize; x++ {
      fmt.Print("*")
    }
    fmt.Println()
  }
}
