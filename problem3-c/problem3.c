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

        compound = input;

        for(i = 2; i < sqrt(input); i++)
        {
            if(compound % i == 0) {
                compound = compound / i;

                if(i > prime) {
                    prime = i;
                }

                i = 2;
            }
        }

        printf("%ld\n", prime);
}
