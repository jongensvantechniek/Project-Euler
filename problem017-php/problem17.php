<?php

/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

*/

function writenumberout($number)
{
    $order0 = ['zero',  'one', 'two',   'three', 'four', 'five', 'six',  'seven',  'eight', 'nine'];
    $order1 = ['naught','teen','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety'];
    $exceptions = ['ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen'];

    $ten_flag = false;
    $dec_flag = false;

    $result = '';

    // Split digits from the number into an array
    $digits_as_array = array_map('intval', str_split($number));

    // Reverse array for easier handling of the digits
    $digits_as_array = array_reverse($digits_as_array);

    // Check if number has a magnitude order of three
    if (count($digits_as_array) > 3) {
        // Check if the highest order equals one, if so then start the string
        // with one thousand
        if ($digits_as_array[3] == 1) {
            $result = 'one thousand';
        }
    }

    // Check if number has a magnitude order of two
    if (count($digits_as_array) > 2) {
        if ($digits_as_array[2] > 0) {
            // If there already is a string in building, we need to concatenate
            // this string value with 'and' in order to respect british
            // spelling.
            if ($result) {
                $result = $result.' and ';
            }

            // Fetch the 0th order number concatenated with hundred,
            // this also includes 'one hundred'
            $result = $order0[$digits_as_array[2]].' hundred';
        }
    }

    // Check if number has a magnitude order of one
    if (count($digits_as_array) > 1) {

        // If there already is a string in building, we need to concatenate
        // this string value with 'and' in order to respect british
        // spelling... Unless the first magnitude has not been set.
        if ($result && $digits_as_array[1] > 0) {
            $result = $result.' and ';
        }

        // If the number starts with a 2, 3, ... 8, 9 then the number can
        // easily be constructed by the first order naming conventions for
        // first magnitude numbers.
        // A flag needs to be set for handling the 0th magnitude order naming
        // convention so we can check whether we need to concat this order
        // with and or the 0th order.
        if ($digits_as_array[1] > 1) {
            $dec_flag = true;
            $result = $result.$order1[$digits_as_array[1]];
        }

        // If the number starts with 1 we run into a lot of exceptions to the
        // the rule for british naming conventions for numbers.
        // If the ten_flag is set, then the 0th order naming concatenation is
        // no longer required.
        if ($digits_as_array[1] == 1) {
            $ten_flag = true;

            // Scary exceptions can be easily fixed by reading the array
            // of naming exceptions. Else the number can be build with a
            // 'teen'-suffix.
            if ($digits_as_array[0] < count($exceptions)) {
                $result = $result.$exceptions[$digits_as_array[0]];
            } else {
                $result = $result.$order0[$digits_as_array[0]].$order1[$digits_as_array[1]];
            }
        }
    }

    // Check if number has a magnitude order of zero
    if (count($digits_as_array) > 0 && !$ten_flag) {
        if ($digits_as_array[0] > 0) {
            // If there was no digit involved in the 1st magnitude we
            // need to concat 'and' in order to respect british spelling.
            if ($result && !$dec_flag) {
                $result = $result.' and ';
            }

            // Use the 0th order array to read the last single digit.
            $result = $result.$order0[$digits_as_array[0]];
        }
    }

    return $result;
}

$sum = 0;

// Start counting from 1000 to 1.
for ($i = 1000; $i > 0; --$i) {
    // Generate the written out number.
    $word = writenumberout($i);

    $search = array('-', ' ');
    $replace = '';

    // Search and destroy spaces and hyphens.
    $word = str_replace($search, $replace, $word);

    // Count word length and add it to the sum.
    $sum = $sum + strlen($word);
}

// Produce the answer.
echo $sum."\n";
