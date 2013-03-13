Suffix Structure Implementation
===============================
by [Cole Lyman](http://colelyman.com), [Brigham Young University](http://byu.edu) [Computational Science Lab](http://csl.cs.byu.edu)
Purpose
--------
The purpose of this implementation is to create an efficient implementation of various suffix structures (suffix array, suffix tree, and suffix cacts).
Input
--------
The input to generate a structure is basically:
 * a reference string- the text that you want to construct the structure with, whether it be a genome, or any other long string.
 * a string delimiter- a character that does not occur anywhere in the reference string, commonly a ``$``.
Output
--------
The following functions will produce the following outputs:
 * print()- will return a string of the array.
 * intFind(string query)- will return an integer of the location of the suffix in relation to the reference, if the query is not present it will return ``-1``.
 * boolFind(string query)- will return a boolean of whether or not the query is a suffix of the reference.
