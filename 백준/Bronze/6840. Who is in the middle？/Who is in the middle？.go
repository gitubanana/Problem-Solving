package main

import (
  "fmt"
  "sort"
)

func main() {
  const size int = 3

  arr := []int{0, 0, 0}
  for i := 0; i < size; i++ {
    fmt.Scan(&arr[i])
  }

  sort.Slice(arr, func(i, j int) bool {
    return arr[i] < arr[j]
  })

  fmt.Println(arr[size - 2])
}
