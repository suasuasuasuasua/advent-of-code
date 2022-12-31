package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Reading files may produce many errors
func check(e error) {
	if e != nil {
		panic(e)
	}
}

// Create each Elf's backpack
type elf struct {
	item int
}

// Sum the given elves
func sum(items []elf) int {
	total := 0
	for _, item := range items {
		total += item.item
	}
	return total
}

func main() {
	f, err := os.Open("input.txt")
	check(err) // Open the file and check for an error
	defer f.Close()

	scanner := bufio.NewScanner(f) // Create a scanner object from the file object

	all_elves := []elf{}
	current_elf := 0
	// Scan the file line by line, stopping at each newline
	for scanner.Scan() {
		line := scanner.Text()
		if line == "" {
			all_elves = append(all_elves, elf{current_elf})
			current_elf = 0
			continue
		} else {
			item, err := strconv.Atoi(line)
			check(err)
			current_elf += item
		}
	}

	// Reverse sort the elves by item
	sort.Slice(all_elves, func(l, r int) bool {
		return all_elves[l].item > all_elves[r].item
	})

	part_1 := sum(all_elves[:1])
	fmt.Println("Part 1:", part_1)

	part_2 := sum(all_elves[:3])
	fmt.Println("Part 2:", part_2)
}
