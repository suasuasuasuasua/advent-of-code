import hashlib

input: str = """yzbqklnj"""

curNum = 0
saveNum_p1 = 0
while True:
    toHash = input + str(curNum)
    result = hashlib.md5(toHash.encode())
    if (result.hexdigest()[:5] == "00000"):
        saveNum_p1 = curNum
        break
    curNum += 1

saveNum_p2 = 0
while True:
    toHash = input + str(curNum)
    result = hashlib.md5(toHash.encode())
    if (result.hexdigest()[:6] == "000000"):
        saveNum_p2 = curNum
        break
    curNum += 1

print(f"Part 1: {saveNum_p1}")
print(f"Part 2: {saveNum_p2}")
