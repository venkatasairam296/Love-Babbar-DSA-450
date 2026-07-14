/*
------------------------------------------------------------
Problem:
Given an array arr, return the minimum and maximum elements
present in the array.

Approach: Sorting

Logic:
- Sort the array in ascending order.
- After sorting:
  - The first element is the minimum.
  - The last element is the maximum.
- Return both values as a vector.

Example:
Input:
arr = [3, 2, 1, 5, 4]

Step-by-step:
- Sort the array -> [1, 2, 3, 4, 5]
- Minimum = 1
- Maximum = 5

Output:
[1, 5]

Time Complexity:
O(n log n)
- Sorting the array takes O(n log n).

Space Complexity:
O(1)
- Ignoring the space used internally by the sorting algorithm.
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> getMinMax(vector<int>& arr) {

        // Sort the array in ascending order
        sort(arr.begin(), arr.end());

        // First element is minimum, last element is maximum
        return {arr.front(), arr.back()};
    }
};