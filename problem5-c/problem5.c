#include <stdio.h>
#include <stdbool.h>

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

int main()
{
        int a,b,c;

        // For each natural number up to... Close to infinity.
        for(a = 1;; a++)
        {
                // Be positive and make the assumption you 
                // found the smallest number that is divisible by 1 to 20.
                bool c = 1;
                
                // Try to break the posivity and test the number against
                // dividing it by 1, 2, 3, ... , 20.
                for(b = 2; b <= 20; b++) {
                        if(a % b != 0) {
                            // Clearly failed a clean division.
                            c = 0;
                        }
                }

                // Being positive has paid off! The number we found is
                // divisible by each number from 1 to 20.
                if(c) {
                        printf("%d\n", a);
                        break;
                }
        }
}
