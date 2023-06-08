def no_of_digits(n):
    count = 0

    while(n > 0):
        n //= 10
        count += 1

    return count
  
a = 1
b = 1
temp = int()
i = 3

while(i):
    temp = a + b
    a = b
    b = temp
    if no_of_digits(temp) == 1000: print(i)
    i += 1
