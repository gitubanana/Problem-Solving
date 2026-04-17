package main

import (
  "fmt"
)

func main() {
  var coinCnt, price int

  fmt.Scan(&coinCnt, &price)
  if coinCnt * 100 >= price {
    fmt.Println("Yes")
  } else {
    fmt.Println("No")
  }
}
