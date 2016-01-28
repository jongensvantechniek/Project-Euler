/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/
function problem1()
{
	var total = 0, until = 1000;
	for (var i = 3; i < until; i += 1) {
		// Use mod to calculate if a number is dividable by itself, if so add it to the total sum
		if (i % 3 === 0 || i % 5 === 0) {
			total += i;
		}
	}
	return total;
}
