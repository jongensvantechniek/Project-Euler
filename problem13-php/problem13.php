<?php

/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

(See list.txt)
*/

$handle = fopen('list.txt', 'r');

$sum = 0;

if ($handle) {
    while (($line = fgets($handle)) !== false) {
        // Summate the first twelf digits of each number.
        // Since there are less than 100 numbers in the list,
        // it's safe to assume there will be no issues
        // with the significance of the number.
        $sum = $sum + substr($line, 0, 12);
    }

    // Return the first ten digits of the sum.
    echo substr($sum, 0, 10)."\r\n";

    fclose($handle);
} else {
    echo 'Unable to read file';
}
