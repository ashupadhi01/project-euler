def no_of_digits(n):
    count = 0

    while(n > 0):
        n //= 10
        count += 1

    return count


sum = 0
with open("file.txt", "r") as f:
    for i in f:
        sum += int(i)

k = no_of_digits(sum)
print(sum // 10 ** (k - 10))


# file.txt contains 100 fifty digit numbers such that each number is in a given line.
