package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func Check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	file, err := os.Open("input.txt")
	Check(err)

	scanner := bufio.NewScanner(file)
	lines := []string{}
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}

	priority := make(map[uint8]int)
	var c uint8
	for c = 'a'; c <= 'z'; c++ {
		priority[c] = int(c-'a') + 1
	}
	for c = 'A'; c <= 'Z'; c++ {
		priority[c] = int(c-'A') + 27
	}

	part_1 := 0
	for _, line := range lines {
		length := len(line)
		left_half := line[:length/2]
		right_half := line[length/2:]
		for _, c := range left_half {
			if strings.Contains(right_half, string(c)) {
				part_1 += priority[uint8(c)]
				break
			}
		}
	}

	part_2 := 0
	for i := 0; i < len(lines); {
		first := lines[i]
		second := lines[i+1]
		third := lines[i+2]
		for _, c := range first {
			if strings.Contains(second, string(c)) && strings.Contains(third, string(c)) {
				part_2 += priority[uint8(c)]
				break
			}
		}
		i += 3
	}

	fmt.Println("Part 1: ", part_1)
	fmt.Println("Part 2: ", part_2)
}
