#!/usr/bin/python3

# Function to check if a number is a palindrome
def is_palindrome(num):
    return str(num) == str(num)[::-1]

# Variables to store the largest palindrome and its factors
largest_palindrome = 0
factors = (0, 0)

# Loop through all possible 3-digit numbers
for i in range(100, 1000):
    for j in range(100, 1000):
        product = i * j
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product
            factors = (i, j)

# Save the result in the file '102-result'
with open('102-result', 'w') as file:
    file.write(str(largest_palindrome))
