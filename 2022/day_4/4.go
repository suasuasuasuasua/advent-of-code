package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func Check(e error) {
	if e != nil {
		panic(e)
	}
}

func MapToInt(strings []string) []int {
	m := make([]int, len(strings))
	for i, v := range strings {
		n, _ := strconv.Atoi(v)
		m[i] = n
	}
	return m
}

func main() {
	file, err := os.Open("input.txt")
	// file, err := os.Open("test.txt")
	Check(err)
	defer file.Close()

	scanner := bufio.NewScanner(file)
	lines := []string{}
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}

	part_1 := 0
	part_2 := 0
	for _, line := range lines {
		line := strings.Split(line, ",")
		first := MapToInt(strings.Split(line[0], "-"))
		second := MapToInt(strings.Split(line[1], "-"))

		// Check if either range encloses the other
		if (first[0] <= second[0] && first[1] >= second[1]) || (second[0] <= first[0] && second[1] >= first[1]) {
			part_1++
		}

		// Check if the ranges overlap or enclose each other
		if (first[0] <= second[0] && first[1] >= second[0]) || (second[0] <= first[0] && second[1] >= first[0]) {
			part_2++
		}
	}

	fmt.Println("Part 1: ", part_1)
	fmt.Println("Part 2: ", part_2)
}
