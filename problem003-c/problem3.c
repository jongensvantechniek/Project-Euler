#include <stdio.h>
#include <math.h>

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

int main()
{
        long input, i, compound;
        long prime = -1;
        
        input = 600851475143;

        // Set remaining compound number equal to 600851475143.
        compound = input;

        // Loop through natural numbers between two and largest possible factor.
        for(i = 2; i < sqrt(input); i++)
        {
            // If the compound number is divisible
            if(compound % i == 0) {
                // Set the compound number to the remainder of the factor.
                compound = compound / i;

                // If we find a prime factor larger than the previous factor
                if(i > prime) {
                    // Set the largest found prime factor equal to the factor.
                    prime = i;
                }

                // And reset the loop to try again.
                i = 2;
            }
        }

        printf("%ld\n", prime);
}
