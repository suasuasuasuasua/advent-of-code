def slope_descent(field: list, dx: int, dy: int):
    x, y = len(field), len(field[0])
    i = j = 0

    count = 0
    while i < x:
        count += 1 if field[i][j] == "#" else 0
        i += dx
        j = (j + dy) % y

    return count


def main():
    # file: str = "sample.txt"
    file: str = "input.txt"
    field: list = list()
    with open(file=file, mode="r") as fr:
        line = fr.readline()
        while (line != ""):
            field.append(line.rstrip("\n"))
            line = fr.readline()

    p1_count = slope_descent(field, 1, 3)
    p2_count = 1
    for dx, dy in ((1, 1), (1, 3), (1, 5), (1, 7), (2, 1)):
        p2_count *= slope_descent(field, dx, dy)

    print(f"Part 1: {p1_count}")
    print(f"Part 2: {p2_count}")


if __name__ == "__main__":
    main()
