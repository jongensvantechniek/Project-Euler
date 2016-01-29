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

        for(a = 1; a <= 100; a++) {
            sumofsquare = sumofsquare + a * a;
        }

        for(a = 1; a <= 100; a++) {
            squareofsum = squareofsum + a;
        }

        squareofsum = squareofsum * squareofsum;

        difference = squareofsum - sumofsquare;

        printf("%ld\n", difference);
}
