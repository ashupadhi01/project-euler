def fact(a):
    result = 1
    for i in range(1, a + 1): result *= i
    return result


count = 0

for i in range(23, 101):
    for j in range(1, i+1):
        a = fact(i)
        b = fact(i - j) * fact(j)
        a /= b
        if a >= 1000000: count += 1

print(count)

# NOTE:
# This is a brute force approach where I computed all the valid combinations for n equals to 100, and checked how many outputs number greater than 1 million.
