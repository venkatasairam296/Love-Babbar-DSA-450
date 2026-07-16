/*
------------------------------------------------------------
Problem:
Given an array arr and an integer k, return the kth smallest
element in the array.

Approach: Sorting

Logic:
- Sort the array in ascending order.
- After sorting, the kth smallest element will be at index k-1.
- Return that element.

Example:
Input:
arr = [7, 10, 4, 3, 20, 15], k = 3

Step-by-step:
Sorted array = [3, 4, 7, 10, 15, 20]
3rd smallest element = 7

Output:
7

Time Complexity:
O(n log n)

Space Complexity:
O(1)
(Ignoring the internal space used by the sorting algorithm.)
------------------------------------------------------------
*/

class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {

        // Sort the array
        sort(arr.begin(), arr.end());

        // Return the kth smallest element
        return arr[k - 1];
    }
};