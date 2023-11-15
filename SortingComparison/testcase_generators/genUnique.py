import random

n = int(input("Enter the number of unique integers: "))
max_range = 2147483647

# Generate a list of n unique integers between 0 and max_range
numbers = random.sample(range(max_range), n)

# Write the numbers to a file
with open('input.txt', 'w') as f:
    for number in numbers:
        f.write(str(number) + '\n')