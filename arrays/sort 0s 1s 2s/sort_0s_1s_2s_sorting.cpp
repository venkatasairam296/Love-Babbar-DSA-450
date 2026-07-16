/*
------------------------------------------------------------
Problem:
Given an array consisting only of 0s, 1s, and 2s, sort the array
in ascending order without using any built-in sorting assumptions.

Approach: Sorting

Logic:
- Use the built-in sort() function.
- After sorting, all 0s come first, followed by 1s and then 2s.

Example:
Input:
arr = [0, 2, 1, 2, 0]

Step-by-step:
Sort the array:
[0, 0, 1, 2, 2]

Output:
[0, 0, 1, 2, 2]

Time Complexity:
O(n log n)

Space Complexity:
O(1)
(Ignoring the internal space used by the sorting algorithm.)
------------------------------------------------------------
*/

class Solution {
public:
    void sort012(vector<int>& arr) {

        // Sort the entire array
        sort(arr.begin(), arr.end());
    }
};