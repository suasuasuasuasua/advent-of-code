"""--- Day 4: Ceres Search ---

"Looks like the Chief's not here. Next!" One of The Historians pulls out a
device and pushes the only button on it. After a brief flash, you recognize the
interior of the Ceres monitoring station!

As the search for the Chief continues, a small Elf who lives on the station tugs
on your shirt; she'd like to know if you could help her with her word search
(your puzzle input). She only has to find one word: XMAS.

--- Part One ---

This word search allows words to be horizontal, vertical, diagonal, written
backwards, or even overlapping other words. It's a little unusual, though, as
you don't merely need to find one instance of XMAS - you need to find all of
them. Here are a few ways XMAS might appear, where irrelevant characters have
been replaced with .:

..X...
.SAMX.
.A..A.
XMAS.S
.X....

The actual word search will be full of letters instead. For example:

MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX

In this word search, XMAS occurs a total of 18 times; here's the same word
search again, but where letters not involved in any XMAS have been replaced with
.:

....XXMAS.
.SAMXMS...
...S..A...
..A.A.MS.X
XMASAMX.MM
X.....XA.A
S.S.S.S.SS
.A.A.A.A.A
..M.M.M.MM
.X.X.XMASX

Take a look at the little Elf's word search. How many times does XMAS appear?

--- Part Two ---

The Elf looks quizzically at you. Did you misunderstand the assignment?

Looking for the instructions, you flip over the word search to find that this
isn't actually an XMAS puzzle; it's an X-MAS puzzle in which you're supposed to
find two MAS in the shape of an X. One way to achieve that is like this:

M.S
.A.
M.S

Irrelevant characters have again been replaced with . in the above diagram.
Within the X, each MAS can be written forwards or backwards.

Here's the same example from before, but this time all of the X-MASes have been
kept instead:

.M.S......
..A..MSMS.
.M.S.MAA..
..A.ASMSM.
.M.S.M....
..........
S.S.S.S.S.
.A.A.A.A..
M.M.M.M.M.
..........

In this example, an X-MAS appears 9 times.

Flip the word search from the instructions back over to the word search side and
try again. How many times does an X-MAS appear?
"""

from pathlib import Path
import numpy as np

file_name = Path("sample.txt")
file_name = Path("input.txt")

with open(file_name, "r") as file_in:
    # Basically make a matrix for all the characters in the file
    data = [[l for l in line.strip()] for line in file_in.readlines()]

# numpy arrays are nicer to work with
data = np.array(data)


# Ref: https://stackoverflow.com/a/43311126
def forward_diags(matrix: np.ndarray) -> list[list[str]]:
    height, width = matrix.shape

    # Make an entry for each of the possible diagonals
    f_diags = [[] for _ in range(height + width - 1)]

    for i in range(height):
        for j in range(width):
            entry = str(matrix[j][i])

            f_diags[i + j].append(entry)

    return f_diags


def backward_diags(matrix: np.ndarray) -> list[list[str]]:
    height, width = matrix.shape

    # Make an entry for each of the possible diagonals
    b_diags = [[] for _ in range(height + width - 1)]
    # Offset the backward diagonal
    min_bdiag = -height + 1

    for i in range(height):
        for j in range(width):
            entry = str(matrix[j][i])

            b_diags[i - j - min_bdiag].append(entry)

    return b_diags


def count_pattern(l: np.ndarray, pattern: str) -> int:
    count = 0
    for entry in l:
        chars = "".join(entry)

        # Find all N-length chunks to search over
        chunks = [
            chars[i : i + len(pattern)] for i in range(0, len(chars) - len(pattern) + 1)
        ]

        # Count the number of times that the pattern appears in forward and
        # reverse order
        count += chunks.count(pattern) + chunks.count(pattern[::-1])

    return count


rows = data.copy()
cols = np.rot90(rows)

f_diags = forward_diags(rows)
b_diags = backward_diags(rows)

p1_pattern = "XMAS"
p1 = (
    count_pattern(rows, p1_pattern)
    + count_pattern(cols, p1_pattern)
    + count_pattern(f_diags, p1_pattern)
    + count_pattern(b_diags, p1_pattern)
)

print(f"Part 1: {p1}")

# Part 2 -- look for sliding 3x3 windows
grids = []
height, width = data.shape
for i in range(height - 3 + 1):
    for j in range(width - 3 + 1):
        grid = [row[j : j + 3] for row in rows[i : i + 3]]
        grids.append(grid)

grids = np.array(grids)

# Search for the two diagonals of MAS in each grid
p2_pattern = "MAS"
p2 = 0
for grid in grids:
    gf_diag = forward_diags(grid)
    gb_diag = backward_diags(grid)

    if count_pattern(gf_diag, p2_pattern) and count_pattern(gb_diag, p2_pattern):
        p2 += 1

print(f"Part 2: {p2}")
