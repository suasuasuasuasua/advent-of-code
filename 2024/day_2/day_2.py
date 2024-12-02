"""
--- Day 2: Red-Nosed Reports ---
Fortunately, the first location The Historians want to search isn't a long walk
from the Chief Historian's office.

While the Red-Nosed Reindeer nuclear fusion/fission plant appears to contain no
sign of the Chief Historian, the engineers there run up to you as soon as they
see you. Apparently, they still talk about the time Rudolph was saved through
molecular synthesis from a single electron.

They're quick to add that - since you're already here - they'd really appreciate
your help analyzing some unusual data from the Red-Nosed reactor. You turn to
check if The Historians are waiting for you, but they seem to have already
divided into groups that are currently searching every corner of the facility.
You offer to help with the unusual data.

--- Part One ---

The unusual data (your puzzle input) consists of many reports, one report per
line. Each report is a list of numbers called levels that are separated by
spaces. For example:

7 6 4 2 1
1 2 7 8 9
9 7 6 2 1 1 3 2 4 5
8 6 4 4 1
1 3 6 7 9

This example data contains six reports each containing five levels.

The engineers are trying to figure out which reports are safe. The Red-Nosed
reactor safety systems can only tolerate levels that are either gradually
increasing or gradually decreasing. So, a report only counts as safe if both of
the following are true:

- The levels are either all increasing or all decreasing.
- Any two adjacent levels differ by at least one and at most three.

In the example above, the reports can be found safe or unsafe by checking those
rules:

- 7 6 4 2 1: Safe because the levels are all decreasing by 1 or 2.
- 1 2 7 8 9: Unsafe because 2 7 is an increase of 5.
- 9 7 6 2 1: Unsafe because 6 2 is a decrease of 4.
- 1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is decreasing.
- 8 6 4 4 1: Unsafe because 4 4 is neither an increase or a decrease.
- 1 3 6 7 9: Safe because the levels are all increasing by 1, 2, or 3.

So, in this example, 2 reports are safe.
Analyze the unusual data from the engineers. How many reports are safe?

--- Part Two ---

The engineers are surprised by the low number of safe reports until they realize
they forgot to tell you about the Problem Dampener.

The Problem Dampener is a reactor-mounted module that lets the reactor safety
systems tolerate a single bad level in what would otherwise be a safe report.
It's like the bad level never happened!

Now, the same rules apply as before, except if removing a single level from an
unsafe report would make it safe, the report instead counts as safe.

More of the above example's reports are now safe:

- 7 6 4 2 1: Safe without removing any level.
- 1 2 7 8 9: Unsafe regardless of which level is removed.
- 9 7 6 2 1: Unsafe regardless of which level is removed.
- 1 3 2 4 5: Safe by removing the second level, 3.
- 8 6 4 4 1: Safe by removing the third level, 4.
- 1 3 6 7 9: Safe without removing any level.

Thanks to the Problem Dampener, 4 reports are actually safe!

Update your analysis by handling situations where the Problem Dampener can
remove a single level from unsafe reports. How many reports are now safe?
"""

from pathlib import Path

import numpy as np


# input_file = Path("./sample.txt")
input_file = Path("./input.txt")

data = []

with open(input_file, "r") as file_in:
    for line in file_in:
        line = line.strip().split()
        data.append([int(i) for i in line])

MIN_DIFF = 1
MAX_DIFF = 3

part_1 = 0
part_2 = 0


def check_report(report: list[int], part_2: bool = False) -> bool:
    diff = np.diff(report)
    # -1 0 1 are the possible values
    signs = np.sign(diff)
    # [ -1 ] [ 1 ] indicate that the values are all decreasing or increasing
    #  respectively
    # [ 0 ] [ -1 0 ] [ -1 1 ] [ 0 1 ] [-1 0 1] are also possible values which
    # indicate some mix of signs (not good!)
    u_signs = np.unique(signs)

    # Count up the frequency for each sign
    freq_counts = {k: v for k, v in np.array(np.unique(signs, return_counts=True)).T}
    sorted_counts = sorted(freq_counts, key=freq_counts.get, reverse=True)

    # Swap the min and max diff for increasing and decreasing orders (majority)
    min_d, max_d = (
        (MIN_DIFF, MAX_DIFF) if (sorted_counts[0] == 1) else (-MAX_DIFF, -MIN_DIFF)
    )

    # Check all the differences are within bounds
    is_in_bounds = np.greater_equal(diff, min_d) & np.less_equal(diff, max_d)

    # Part 2
    if part_2:
        # Only dealing with 1d data so we don't care about having it in a tuple
        candidates = np.array(np.where(is_in_bounds == False)).flatten()

        # All good! no candidates to remove OR too many! just want one level
        if candidates.size == 0:
            return is_in_bounds

        # Candidates for removal
        for candidate in candidates:
            l, r = candidate, candidate + 1

            # Try removing the left
            ll = report[:l] + report[l + 1 :]
            lx = check_report(ll)
            # Try removing the right
            rl = report[:r] + report[r + 1 :]
            rx = check_report(rl)

            # One or the other needs to be "correct"
            final = np.all(lx) | np.all(rx)

            if final:
                return final

    return is_in_bounds


for report in data:
    checked_1 = check_report(report)
    checked_2 = check_report(report, part_2=True)

    if np.all(checked_1):
        part_1 += 1

    if np.all(checked_2):
        part_2 += 1

print(f"Part 1: {part_1}")
print(f"Part 2: {part_2}")
