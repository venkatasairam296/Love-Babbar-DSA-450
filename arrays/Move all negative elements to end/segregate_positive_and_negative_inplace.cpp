/*
------------------------------------------------------------
Problem:
Given an array of integers, rearrange the elements such that all
non-negative elements appear first, followed by all negative
elements, while preserving the relative order of appearance.

Approach: In-place Stable Partition (Insertion Technique)

Logic:
- Traverse the array from left to right.
- Whenever a non-negative element is found:
  - Move it left by swapping it with adjacent negative elements.
  - Continue swapping until it reaches its correct position.
- This maintains the original relative order of both non-negative
  and negative elements.
- The idea is similar to the insertion process in Insertion Sort.

Example:
Input:
arr = [-5, 7, -3, 4, -2, 8]

Step-by-step:
Initial:
[-5, 7, -3, 4, -2, 8]

Move 7 left:
[7, -5, -3, 4, -2, 8]

Move 4 left:
[7, 4, -5, -3, -2, 8]

Move 8 left:
[7, 4, 8, -5, -3, -2]

Output:
[7, 4, 8, -5, -3, -2]

Time Complexity:
O(n²)
- In the worst case, each non-negative element may be shifted
  across multiple negative elements.

Space Complexity:
O(1)
- Rearrangement is performed in-place.
------------------------------------------------------------
*/

class Solution {
public:
    void segregateElements(vector<int>& arr) {
        int n = arr.size();

        // Move each non-negative element towards the front
        while preserving its relative order
        for (int i = 0; i < n; i++) {

            if (arr[i] >= 0) {
                int j = i;

                // Shift the current element left across negatives
                while (j > 0 && arr[j - 1] < 0) {
                    swap(arr[j], arr[j - 1]);
                    j--;
                }
            }
        }
    }
};