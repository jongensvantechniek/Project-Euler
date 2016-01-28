/**
    If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these
    multiples is 23.

    Find the sum of all the multiples of 3 or 5 below 1000.
*/

let MAX = 1000                              // Upperbound
let factors:Array<Int> = [3,5]              // Factors to check for multiples

/*
    Iterates through the given Natural numbers collection.
    If an element of the Natural numbers collections is a multiple
    of the given factors, add it to the current sum.
*/

func findSum()-> Int {
    var sumOfMultiples:Int = 0              // Initialize and set sum to 0

    for i in factors.minElement()!..<MAX {  // Iterate from lowerbound to upperbound.
        for j in factors {                  // Iterate over given factors.
            if i % j == 0 {                 // If current element of the collection N is a multiple of current factor element,
                sumOfMultiples += i         // add the current element to the current sum.
                break
            }
        }
    }

    return sumOfMultiples                   // Return summated result of found factor multiples.
}

print(findSum())                            // Execute functie, print result.
