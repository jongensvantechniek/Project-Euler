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

        for(a = 2;; a++) {

                bool c = 1;

                for(b = 2; b < sqrt(a) + 1; b++) {

                        if(a % b == 0) {
                                c = 0;
                        }
                }

                if(c) {
                        d = d + 1;
                }

                if(d == 10001) {
                        printf("%d\n", a);
                        break;
                }

        }
}
