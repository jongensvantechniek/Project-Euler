#!/usr/bin/python

# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.

# Define an array with only multiples of 3 or 5
range = filter(lambda x: 0 == min(x % 3, x % 5) ,range(1000))

# Sum the array
sum = sum(range)

# Print for the win
print sum
