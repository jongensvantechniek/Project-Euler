/**
    If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these
    multiples is 23.
    Find the sum of all the multiples of 3 or 5 below 1000.
*/

/*
    Iterates through the given Natural numbers collection.
    If an element of the Natural numbers collections is a multiple
    of the given factors, add it to the current sum.
*/
def findSum(){
  def MAX = 1000                                        // Upperbound
  def factors = [3,5]                                   // Factors to check for multiples

  def sum = (factors.min()..<MAX).findAll({ $0 ->       // Iterate from lowerbound to upperbound, close over the closures first argument, the current natural number.
    factors.findAll { $0 % it == 0}}                    // findAll returns the natural number to be added (and gets added to sum), if it meets the condition that it is multiple of current factor element
  ).sum()

  return sum                                            // Return summated multiples of given factors
}

print findSum()                                         //Execute and print result
