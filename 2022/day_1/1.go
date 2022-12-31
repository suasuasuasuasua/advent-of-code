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

func ToInt64(lines []string) []int64 {
	nums := make([]int64, len(lines))
	for i, line := range lines {
		nums[i], _ = strconv.ParseInt(line, 10, 64)
	}
	return nums
}

func Sum(lines []int64) int64 {
	final_sum := int64(0)
	for _, line := range lines {
		final_sum += line
	}
	return final_sum
}

func main() {
	// Open the file for input
	f, err := os.Open("input.txt")
	check(err)
	defer f.Close()

	// Read the file line by line
	scanner := bufio.NewScanner(f)
	all_lines := []string{}
	for scanner.Scan() {
		all_lines = append(all_lines, scanner.Text())
	}

	// Group the lines based on newline
	groups := []int64{}
	start := 0
	for i, line := range all_lines {
		if line == "" {
			groups = append(groups, Sum(ToInt64(all_lines[start:i])))
			start = i + 1
		}
	}
	groups = append(groups, Sum(ToInt64(all_lines[start:])))

	// Sort the groups in descending order
	sort.Slice(groups, func(i, j int) bool {
		return groups[i] > groups[j]
	})

	part_1 := Sum(groups[:1])
	fmt.Println("Part 1: ", part_1)

	part_2 := Sum(groups[:3])
	fmt.Println("Part 2: ", part_2)
}
