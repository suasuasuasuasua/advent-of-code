def isValid(passport):
    # byr(Birth Year) - four digits; at least 1920 and at most 2002.
    # iyr(Issue Year) - four digits; at least 2010 and at most 2020.
    # eyr(Expiration Year) - four digits; at least 2020 and at most 2030.
    # hgt(Height) - a number followed by either cm or in:
    # If cm, the number must be at least 150 and at most 193.
    # If in , the number must be at least 59 and at most 76.
    # hcl(Hair Color) - a  # followed by exactly six characters 0-9 or a-f.
    # ecl(Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
    # pid(Passport ID) - a nine-digit number, including leading zeroes.
    # cid(Country ID) - ignored, missing or not .

    for passport_field, val in passport:
        if (passport_field == "byr" and not (int(val) < 2002 and int(val) > 1920)):
            return False
        elif (passport_field == "iyr" and not (int(val) < 2020 and int(val) > 2010)):
            return False
        elif (passport_field == "eyr" and not (int(val) < 2030 and int(val) > 2020)):
            return False
        elif (passport_field == "hgt"):
            if (val[-2:] == "cm" and not (int(val[:-2]) < 193 and int(val[:-2]) > 150)):
                return False
            if (val[-2:] == "in" and not (int(val[:-2]) < 76 and int(val[:-2]) > 59)):
                return False
        elif (passport_field == "hcl" and not (all([(i in ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')) or (i in ('a', 'b', 'c', 'd', 'e', 'f')) for i in val[1:]]) and val[0] == "#")):
            return False
        elif (passport_field == "ecl" and not (val in ("amb", "blu", " brn", " gry", " grn", " hzl", " oth",))):
            return False
        elif (passport_field == "pid") and not (all([(i in ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')) for i in val[1:]])):
            return False

    return True


def main():
    # file: str = "sample.txt"
    file: str = "input.txt"
    passport_data: list = list()
    with open(file=file, mode="r") as fr:
        passport = ""
        line = fr.readline()
        while line != "":
            passport += line
            line = fr.readline()
            if line == "\n":
                passport_data.append(
                    list(field.split(":") for field in passport.split()))
                passport = ""

    valid_fields = ("byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid")
    p1_count = 0
    p2_count = 0
    for passport in passport_data:
        count = 0
        has_cid = False
        for passport_field, val in passport:
            if passport_field in valid_fields:
                count += 1
            if passport_field == "cid":
                has_cid = True
        if (count == len(valid_fields)):
            p1_count += 1
        elif (not has_cid and count == len(valid_fields) - 1):
            p1_count += 1

        if (count == len(valid_fields) and isValid(passport)):
            p2_count += 1
        elif (not has_cid and count == len(valid_fields) - 1 and isValid(passport)):
            p2_count += 1

    print(f"Part 1: {p1_count}")
    print(f"Part 2: {p2_count}")


if __name__ == "__main__":
    main()
