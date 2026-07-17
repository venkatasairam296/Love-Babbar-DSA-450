/*
------------------------------------------------------------
Problem:
Given an array of integers, rearrange the elements such that all
non-negative elements appear first, followed by all negative
elements, while preserving the relative order of appearance.

Approach: Temporary Array (Stable Partition)

Logic:
- Create a temporary array of the same size as the original array.
- Traverse the array and copy all non-negative elements into the
  temporary array.
- Traverse the array again and copy all negative elements.
- Copy the rearranged elements back to the original array.
- This approach preserves the relative order of both positive and
  negative elements.

Example:
Input:
arr = [-5, 7, -3, 4, -2, 8]

Step-by-step:
Positive/Zero elements -> [7, 4, 8]
Negative elements      -> [-5, -3, -2]

Merged array:
[7, 4, 8, -5, -3, -2]

Output:
[7, 4, 8, -5, -3, -2]

Time Complexity:
O(n)
- One traversal for non-negative elements.
- One traversal for negative elements.
- One traversal to copy back.

Space Complexity:
O(n)
- Extra array is used to store the rearranged elements.
------------------------------------------------------------
*/

class Solution {
public:
    void segregateElements(vector<int>& arr) {
        int n = arr.size();

        // Temporary array to store the rearranged elements
        vector<int> temp(n);
        int idx = 0;

        // Store all non-negative elements first
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                temp[idx++] = arr[i];
            }
        }

        // Store all negative elements while preserving their order
        for (int i = 0; i < n && idx < n; i++) {
            if (arr[i] < 0) {
                temp[idx++] = arr[i];
            }
        }

        // Copy the result back to the original array
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};