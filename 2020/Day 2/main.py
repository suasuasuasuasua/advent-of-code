def main():
    # file: str = "sample.txt"
    file: str = "input.txt"
    password_data: list = list()
    with open(file=file, mode="r") as fr:
        line = fr.readline()
        while (line != ""):
            split = line.split()
            password_data.append(
                (list(map(int, (split[0].split(sep="-")))),
                 split[1][0], split[2])
            )
            line = fr.readline()

    p1_count = 0
    p2_count = 0
    for password in password_data:
        (min, max), target, str = password
        p1_count += 1 if str.count(
            target) >= min and str.count(target) <= max else 0
        p2_count += 1 if ((str[min-1] == target) ^ (str[max-1] == target)) else 0

    print(f"Part 1: {p1_count}")
    print(f"Part 2: {p2_count}")


if __name__ == "__main__":
    main()
