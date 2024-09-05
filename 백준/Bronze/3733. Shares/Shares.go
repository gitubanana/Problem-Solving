package main

import "fmt"

func main() {
  for {
    var people, total int

    _, error := fmt.Scan(&people, &total)
    if error != nil {
      break
    }

    fmt.Println(total / (people + 1))
  }
}
