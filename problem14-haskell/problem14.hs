listOfSequences = map collatzSequence [1..1000000]
listOfSubsetLengths = map length listOfSequences

main = print $ snd . maximum $ zip listOfSubsetLengths [1..]

collatz :: Integer -> Integer

collatz 1 = 1
collatz n = if (odd n)
    then (3 * n + 1)
    else n `div` 2

collatzSequence :: Integer -> [Integer]
collatzSequence = terminate . iterate collatz
    where
    terminate (1:_) = [1]
    terminate (x:xs) = x:terminate xs
