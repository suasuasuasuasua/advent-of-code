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
	// Read in the file line by line
	f, err := os.Open("input.txt")
	Check(err)

	scanner := bufio.NewScanner(f)
	all_lines := []string{}
	for scanner.Scan() {
		all_lines = append(all_lines, scanner.Text())
	}

	// Map all of the moves to 0,1,2
	move_map := map[string]int{
		"A": 0,
		"B": 1,
		"C": 2,
		"X": 0,
		"Y": 1,
		"Z": 2,
	}

	part_1 := 0
	part_2 := 0

	for _, l := range all_lines {
		split_line := strings.Split(l, " ")
		opponent, me := split_line[0], split_line[1]

		// Add the points for whatever we chose
		// Weird negative modulus workaround
		// Basically, a win=2, tie=1, loss=0
		outcome := ((move_map[me]-move_map[opponent]+1)%3 + 3) % 3
		// Multiply the outcome by 3 to get the outcome score
		part_1 += outcome*3 + move_map[me] + 1

		my_move := ((move_map[opponent]-1+move_map[me])%3 + 3) % 3
		part_2 += move_map[me]*3 + my_move + 1
	}

	fmt.Println("Part 1: ", part_1)
	fmt.Println("Part 2: ", part_2)
}
