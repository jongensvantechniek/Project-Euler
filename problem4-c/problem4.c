#include <stdio.h>

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

int main()
{
        int a,b,answer=0;
        
        // For each factor a below the number 999 and above the number of 100
        for(a = 999; a > 99; a--) {
            // For each factor b below the number 999 and above the number of 100
            for(b = 999; b > 99; b--) {
                // Create the compound factor
                int c = a * b;
                
                // Reverse the number
                int reverse = 0, n;
                n = c;
                while(n != 0)
                {
                    // By swapping the order of each digit
                    reverse = reverse * 10;
                    reverse = reverse + n % 10;
                    n = n / 10;
                    
                    // If the reverse number equals the original compound factor.
                    if(c == reverse) {
                        // And it's the largest compound factor palindrome.
                        if(c > answer) {
                            // Set the new record!
                            answer = c;
                        }
                    }
                }

            }
        }

        printf("%d\n", answer);
}
