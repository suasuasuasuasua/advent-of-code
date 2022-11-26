def two_sum(nums: list, target=2020):
    num_dict = dict()
    for num in nums:
        if (num in num_dict):
            return (num, num_dict[num])
        num_dict[target-num] = num
    return None, None


def three_sum(nums: list, target=2020):
    for a in nums:
        partial_sum: int = target - a
        b, c = two_sum(nums=nums, target=partial_sum)
        if (b is not None and c is not None):
            return a, b, c


def main():
    nums = list()
    # file = "sample.txt"
    file = "input.txt"
    with open(file=file, mode="r") as fr:
        line = fr.readline()
        while (line != ""):
            nums.append(int(line))
            line = fr.readline()
    a, b = two_sum(nums=nums)
    print(f"Part 1: {a * b}")

    a, b, c = three_sum(nums=nums)
    print(f"Part 2: {a * b * c}")


if __name__ == "__main__":
    main()
