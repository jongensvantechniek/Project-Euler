#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

int main()
{
        int a,b,d=1;

        // Loop through all natural numbers from 2 to INFINITYYYYYYY
        for(a = 2;; a++) {

                // Make the positive assumption we found a prime!
                bool c = 1;

                // Loop from 2 up to the square root + 1 of the natural number.
                // If you are hardcore, you can loop any further...
                // But you won't find any primes.
                for(b = 2; b < sqrt(a) + 1; b++) {

                        // Test the number against the factor.
                        if(a % b == 0) {
                                // Sad times. This is not a prime number.
                                c = 0;
                        }
                }
                
                // Up the counter! Prime found!
                if(c) {
                        d = d + 1;
                }

                // If the counter equals 10001, we are allowed to make the
                // safe assumption that we found the 10001st prime.
                if(d == 10001) {
                        printf("%d\n", a);
                        // Break the loop. Time to party.
                        break;
                }

        }
}
