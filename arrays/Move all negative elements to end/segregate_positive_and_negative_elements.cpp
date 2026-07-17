/*
------------------------------------------------------------
Problem:
Given an array of integers, move all positive elements to the
beginning of the array and all negative elements to the end
while preserving their relative order.

Approach: Extra Array (Stable Partition)

Logic:
- Create a temporary array of the same size.
- Traverse the original array and copy all positive elements
  into the temporary array.
- Traverse the array again and copy all negative elements.
- Copy the temporary array back to the original array.
- Since elements are copied in their original order, the
  relative ordering of both positive and negative elements
  remains unchanged.

Example:
Input:
arr = [-5, 7, -3, 4, -2, 8]

Step-by-step:
Positive elements -> [7, 4, 8]
Negative elements -> [-5, -3, -2]

Final array:
[7, 4, 8, -5, -3, -2]

Output:
[7, 4, 8, -5, -3, -2]

Time Complexity:
O(n)
- Two traversals to build the temporary array.
- One traversal to copy the result back.

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

        // Store all positive elements first
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
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