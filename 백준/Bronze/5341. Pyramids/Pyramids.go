package main

import "fmt"

func main() {
  var base int;

  for {
    fmt.Scan(&base)
    if base == 0 {
      break
    }

    fmt.Println(base * (base + 1) / 2)
  }
}
