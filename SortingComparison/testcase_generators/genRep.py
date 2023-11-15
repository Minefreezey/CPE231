import random

# Total number of integers
total = int(input("Enter the total number of integers: "))

# Calculate the number of repeated and unique numbers
repeat_count = int(total * 0.3)
unique_count = total - repeat_count

# Generate the unique numbers
numbers = random.sample(range(2147483647), unique_count)

# Generate the repeated numbers and add them to the list
for _ in range(repeat_count):
    number = random.choice(numbers)
    numbers.append(number)

# Shuffle the numbers
random.shuffle(numbers)

# Write the numbers to a file
with open('input.txt', 'w') as f:
    for number in numbers:
        f.write(str(number) + '\n')