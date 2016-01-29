#include <stdio.h>

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

int main()
{
        int a,b,answer=0;

        for(a = 999; a > 99; a--) {
            for(b = 999; b > 99; b--) {
                int c = a * b;
                int reverse = 0, n;

                n = c;
                while(n != 0)
                {
                    reverse = reverse * 10;
                    reverse = reverse + n % 10;
                    n = n / 10;

                    if(c == reverse) {
                        if(c > answer) {
                            answer = c;
                        }
                    }
                }

            }
        }

        printf("%d\n", answer);
}
