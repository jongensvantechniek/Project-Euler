#include <stdio.h>
#include <stdbool.h>

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

int main()
{
        int a,b,c;

        for(a = 1;; a++)
        {
                bool c = 1;
                for(b = 2; b <= 20; b++) {
                        if(a % b != 0) {
                            c = 0;
                        }
                }

                if(c) {
                        printf("%d\n", a);
                        break;
                }

        }
}
