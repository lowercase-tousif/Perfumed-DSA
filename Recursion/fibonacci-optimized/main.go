package main

import "fmt"

var mem = make([]int, 100005)
var mark = make([]int, 100005)

func fibonacci_optimized(n int) int {

	if n <= 1 {
		return n
	}

	if mark[n] == 1 {
		return mem[n]
	}

	var res = fibonacci_optimized(n-1) + fibonacci_optimized(n-2)

	mem[n] = res
	mark[n] = 1

	return res
}

func main() {
	fmt.Println(fibonacci_optimized(100))
}
