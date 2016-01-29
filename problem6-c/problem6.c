#include <stdio.h>

/*

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

int main()
{
        int a;

        long sumofsquare = 0, squareofsum = 0, difference;

        // Find the sum of squares by looping from 1 to 100.
        for(a = 1; a <= 100; a++) {
            // Keep track of your squares in your sum.
            sumofsquare = sumofsquare + a * a;
        }

        // Find the square of sums by looping from 1 to 100.
        for(a = 1; a <= 100; a++) {
            // Keep track of your sums in your squares.
            squareofsum = squareofsum + a;
        }

        // Fair enough. We still need to square the sum here.
        squareofsum = squareofsum * squareofsum;

        // Calculate the difference between the two.
        difference = squareofsum - sumofsquare;

        printf("%ld\n", difference);
}
