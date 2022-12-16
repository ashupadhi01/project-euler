def no_of_digits(a):
    count = 0

    while(a > 0):
        a = a // 10
        count += 1

    return count

def exp(a, b):
    ans = 1
    for i in range(b): ans *= a
    return ans

count = 0

for i in range(1, 10):
    for j in range(1, 100):
        if no_of_digits(exp(i, j)) == j: count += 1
        else: break

print(count)

"""
Insight on this problem is n-th power of any number after 10 will always exceed *n* number of digits. So, the required numbers are only powers of numbers between [1, 9].
If a ^ n results in a number having more than n digits, then any power of *a* more than *n* will result in a number whose number of digits will be greater than *n*.
"""
