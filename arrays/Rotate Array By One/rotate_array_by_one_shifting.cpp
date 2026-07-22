/*
------------------------------------------------------------
Problem:
Given an array, rotate it clockwise by one position.

Solution Type:
Brute Force

Approach: Element Shifting

Logic:
- Store the last element in a temporary variable.
- Shift every element one position to the right.
- Place the stored last element at index 0.

Example:
Input:
arr = [1, 2, 3, 4, 5]

After shifting:
[1, 1, 2, 3, 4]

Place last element at front:
[5, 1, 2, 3, 4]

Output:
[5, 1, 2, 3, 4]

Time Complexity:
O(n)

Space Complexity:
O(1)
------------------------------------------------------------
*/

class Solution {
public:
    void rotate(vector<int> &arr) {

        // Store the last element
        int temp = arr[arr.size() - 1];

        // Shift all elements one position to the right
        for (int i = arr.size() - 1; i >= 1; i--) {
            arr[i] = arr[i - 1];
        }

        // Place the last element at the beginning
        arr[0] = temp;
    }
};