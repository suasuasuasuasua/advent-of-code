import operator
import math
import functools

input = '''Monkey 0:
  Starting items: 98, 70, 75, 80, 84, 89, 55, 98
  Operation: new = old * 2
  Test: divisible by 11
    If true: throw to monkey 1
    If false: throw to monkey 4

Monkey 1:
  Starting items: 59
  Operation: new = old * old
  Test: divisible by 19
    If true: throw to monkey 7
    If false: throw to monkey 3

Monkey 2:
  Starting items: 77, 95, 54, 65, 89
  Operation: new = old + 6
  Test: divisible by 7
    If true: throw to monkey 0
    If false: throw to monkey 5

Monkey 3:
  Starting items: 71, 64, 75
  Operation: new = old + 2
  Test: divisible by 17
    If true: throw to monkey 6
    If false: throw to monkey 2

Monkey 4:
  Starting items: 74, 55, 87, 98
  Operation: new = old * 11
  Test: divisible by 3
    If true: throw to monkey 1
    If false: throw to monkey 7

Monkey 5:
  Starting items: 90, 98, 85, 52, 91, 60
  Operation: new = old + 7
  Test: divisible by 5
    If true: throw to monkey 0
    If false: throw to monkey 4

Monkey 6:
  Starting items: 99, 51
  Operation: new = old + 1
  Test: divisible by 13
    If true: throw to monkey 5
    If false: throw to monkey 2

Monkey 7:
  Starting items: 98, 94, 59, 76, 51, 65, 75
  Operation: new = old + 5
  Test: divisible by 2
    If true: throw to monkey 3
    If false: throw to monkey 6'''

lines = [[s.strip() for s in l.split('\n')] for l in input.split('\n\n')]

all_monkeys = {}
LCM = 1
for l in lines:
    monkey = int(l[0].split()[1].strip(':'))
    items = list(map(int, l[1].split(': ')[1].split(', ')))
    operation = l[2].split(': ')[1].split()[3:]
    test = int(l[3].split(': ')[1].split()[-1])
    throws = [int(i.split()[-1]) for i in l[4:]]

    all_monkeys[monkey] = [
        items, operation, test, throws
    ]
    LCM *= test

operator_dict = {
    '+': operator.add,
    '*': operator.mul,
}

def run_rounds(n, p1):
    monkey_inspections = {m: 0 for m in all_monkeys}
    for i in range(n):
        # For each monkey in the round
        for monkey, attributes in all_monkeys.items():
            items, operation, test, throws = attributes
            # For each item in the monkey's hands
            for item in items:
                operand = int(operation[1]) if operation[1].isnumeric() \
                    else item
                item %= LCM
                worry = operator_dict[operation[0]](item, operand)
                worry = math.floor(worry / 3.0) if p1 \
                    else worry
                all_monkeys[throws[0]][0].append(worry) if worry % test == 0 \
                    else all_monkeys[throws[1]][0].append(worry)

                monkey_inspections[monkey] += 1
            all_monkeys[monkey][0].clear()

    return monkey_inspections


part_1 = sorted(run_rounds(20, True).values(), reverse=True)
part_1 = part_1[0] * part_1[1]
print(f"Part 1 {part_1}")

part_2 = run_rounds(10000, False)
part_2 = sorted(part_2.values(), reverse=True)
part_2 = part_2[0] * part_2[1]
print(f"Part 2 {part_2}")
