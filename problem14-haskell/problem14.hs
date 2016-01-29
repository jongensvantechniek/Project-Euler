--The following iterative sequence is defined for the set of positive integers:

--n → n/2 (n is even)
--n → 3n + 1 (n is odd)

--Using the rule above and starting with 13, we generate the following sequence:
--13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

--It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

--Which starting number, under one million, produces the longest chain?

--NOTE: Once the chain starts the terms are allowed to go above one million.



-- Generate a list of Collatz sequences with arguments 1 to 1000000.
listOfSequences = map collatzSequence [1..1000000]

-- Generate a list of lengths of Collatz sequences
listOfSubsetLengths = map length listOfSequences

-- Zip indices starting from 1 to the list of the lengths of Collatz sequences
-- Select the largest value pair and print the second value from the pair.
main = print $ snd . maximum $ zip listOfSubsetLengths [1..]

-- The Collatz function to generate the next term.
collatz :: Integer -> Integer
collatz 1 = 1
collatz n = if (odd n)
    then (3 * n + 1)
    else n `div` 2

-- Generate the entire Collatz sequence
collatzSequence :: Integer -> [Integer]
collatzSequence = terminate . iterate collatz
    where
    terminate (1:_) = [1]
    terminate (x:xs) = x:terminate xs
