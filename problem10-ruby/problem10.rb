#!/usr/bin/ruby
require 'prime'

# Generate array of prime numbers up to 2M
primes = Prime.take_while {|p| p < 2000000}

# Sum array of prime numbers up to 2M into answer
answer = primes.inject(:+)

# Print answer
puts answer
