package main

import (
	"fmt"
	"math"
)

var F [1000000]int
var MOD int = 1000000007
var use_modulo bool = true

func bpow(a, e int) (t int) {
	if e == 1 {
		return a
	}
	if e == 0 {
		return 1
	}
	t = bpow(a, e/2)
	t = (t % MOD * t % MOD) % MOD
	if e%2 == 1 {
		t = (t % MOD * a % MOD) % MOD
	}
	return t
}

var a [1001][1001]int

func inv(x int) (res int) {
	return bpow(x, MOD-2) % MOD
}

func C(n, k int) (res int) {
	if use_modulo == true {
		return (((F[n] % MOD) * (inv(F[n-k]) % MOD)) % MOD * (inv(F[k]) % MOD)) % MOD
	} else {
		return (F[n] / (F[n-k] * F[k]))
	}
}

func makePascalandFacts() {
	a[0][0] = 1
	for i := 1; i <= 1000; i++ {
		for j := 1; j <= 1000; j++ {
			a[i][j] = a[i-1][j-1] + a[i-1][j]
		}
	}
	F[0] = 1
	var i int = 1
	for ; i < 1000000; i++ {
		F[i] = (F[i-1] % MOD * i % MOD) % MOD
	}
}

func main() {
	makePascalandFacts()
	var (
		a, b, n int
	)
	fmt.Scanf("%d%d
	for i:= 1

}
