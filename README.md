# Relative Sorting
This project discusses solution to the problem of Relative Sorting.
Relative Sorting is Sorting an array, lets say A1 according to the order defined by another array A2

Explanation of the problem in detail:
Given two arrays A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those are in A2. For the elements not present in A2, append them at last in sorted order. 

For Example: 
Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
       A2[] = {2, 1, 8, 3}
Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}


Solution: 
The idea will be to sort the A1[] array and then according to A2[] and store the elements.

Let the size of A1[] be m and the size of A2[] be n.

* Create a temporary array temp of size m and copy the contents of A1[] to it.
* Create another array visited[] of size m and initialize all entries in it as 0 (false). visited[] is used to mark or make note of the indices of those elements in temp[] which are copied back to A1[] whlle sorting.
* Sort temp[].
* Initialize the starting index idx as 0. Elements will be pushed into this index position of A1[] whenever required.
* Do the following for every element of A2[i] in A2[] :
<br> &emsp; * Binary search for all occurrences of A2[i] in temp[], if present then copy all occurrences to A1[idx] and increment idx.
<br> &emsp; * Also mark the indices of copied elements from temp in visited[] as 1(true).
* Copy all unvisited elements from temp[] to A1[], inrementing idx after every copy.

Thus, now A1[] is sorted relative to A2[].
