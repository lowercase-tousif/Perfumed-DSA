package main

import (
	"fmt"
	"reflect"
)

func bubble_sort(arr []int) {
	n := len(arr)

	for i := range n {
		for j := range n-i-1 {
			if arr[j] > arr[j+1] {
				swapF := reflect.Swapper(arr)
				swapF(j, j+1)
			}
		}
	}

	fmt.Println(arr)
}

func main() {
	var a = []int{5, 6, 8, 9, 1, 2, 0}
	bubble_sort(a)
}
