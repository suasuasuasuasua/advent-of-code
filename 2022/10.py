input = '''noop
noop
addx 6
addx -1
noop
addx 5
addx 3
noop
addx 3
addx -1
addx -13
addx 17
addx 3
addx 3
noop
noop
noop
addx 5
addx 1
noop
addx 4
addx 1
noop
addx -38
addx 5
noop
addx 2
addx 3
noop
addx 2
addx 2
addx 3
addx -2
addx 5
addx 2
addx -18
addx 6
addx 15
addx 5
addx 2
addx -22
noop
noop
addx 30
noop
noop
addx -39
addx 1
addx 19
addx -16
addx 35
addx -28
addx -1
addx 12
addx -8
noop
addx 3
addx 4
noop
addx -3
addx 6
addx 5
addx 2
noop
noop
noop
noop
noop
addx 7
addx -39
noop
noop
addx 5
addx 2
addx 2
addx -1
addx 2
addx 2
addx 5
addx 1
noop
addx 4
addx -13
addx 18
noop
noop
noop
addx 12
addx -9
addx 8
noop
noop
addx -2
addx -36
noop
noop
addx 5
addx 2
addx 3
addx -2
addx 2
addx 2
noop
addx 3
addx 5
addx 2
addx 19
addx -14
noop
addx 2
addx 3
noop
addx -29
addx 34
noop
addx -35
noop
addx -2
addx 2
noop
addx 6
noop
noop
noop
noop
addx 2
noop
addx 3
addx 2
addx 5
addx 2
addx 1
noop
addx 4
addx -17
addx 18
addx 4
noop
addx 1
addx 4
noop
addx 1
noop
noop'''

lines = [i.split() for i in input.split('\n')]

queued_adds = []

for l in lines:
    queued_adds.append(0)
    if len(l) == 2:
        queued_adds.append(int(l[1]))

cycles_of_interest = list(range(20, 220 + 40, 40))
part_1 = 0
X = 1
for i, count in enumerate(queued_adds, start=1):
    if i in cycles_of_interest:
        part_1 += (i * X)
    X += count

print(f"Part 1: {part_1}")

part_2 = 0
X = 1
for i in range(6):
    for j in range(40):
        drawn = '.'
        if (abs(j - X) <= 1):
            drawn = '#'
        X += queued_adds[40 * i + j]
        print(drawn, end='')
    print()

print(f"Part 2: {part_2}")
