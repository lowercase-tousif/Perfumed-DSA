package main

import "fmt"

func expo(a int, b int) int {
	if b == 0 {
		return 1
	}

	if b%2 == 0 {
		var x = expo(a, b/2)
		return x * x
	}

	return expo(a, b-1) * a
}

func main() {
	fmt.Println(expo(5, 10))
}
