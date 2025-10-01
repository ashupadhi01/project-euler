import os
import math

def pos_value(c: str) -> int:
    return ord(c) - 65 + 1

def does_root_exist(value: int) -> bool:
    D = 1 + (8 * value)
    root_D = math.sqrt(D)
    
    if not root_D.is_integer():
        return False
    
    root_one = (-1 + root_D) / 2
    root_two = (-1 - root_D) / 2

    if root_one.is_integer() or root_two.is_integer():
        return True
    
    return False

file = open(os.path.expanduser('~/Downloads/words.txt'), 'r')
words = file.read().split(',')
words = [word.strip('"') for word in words]

num_triangle_words = 0

for word in words:
    word_value = sum([pos_value(char) for char in word])
    if does_root_exist(word_value):
        num_triangle_words += 1

print(num_triangle_words)

"""
NOTE:

The problem boils down to whether the 'word_value' is a sum of natural numbers: [1, n], which means if the 'word_value' is 'K', we need to find out whether any integral root of the quadratic: "pow(n, 2) + n - (2.k)" exists.
"""
