public class Problem12 {
    public static void main(String[] args) {
        int triangles = 0;
        int count;

        // For each natural number up to forever
        for(int i = 1; ; i++) {
            // Get the next triangle number
            triangles = triangles + i;
            count = 0;

            // Let's test it against all possible divisors below the square root
            // of the triangle number itself.
            for(int j = 1; j <= Math.sqrt(triangles); j++) {
                if(triangles % j == 0) {
                    // If the triangle number passes the test to find it's
                    // divisor j you find two divisors, it takes two to tango
                    // and two numbers to multiply.
                    count = count + 2;
                }
            }

            // Break up the party if you find over fivehundred divisors.
            if(count > 500 ) {
                System.out.println(triangles);
                break;
            }
        }
    }
}
