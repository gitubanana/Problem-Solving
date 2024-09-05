package main

import (
  "fmt"
)

func main() {
  var dist int

  fmt.Scan(&dist)

  ans := dist / 5
  if dist % 5 != 0 {
    ans++
  }
  fmt.Println(ans)
}
