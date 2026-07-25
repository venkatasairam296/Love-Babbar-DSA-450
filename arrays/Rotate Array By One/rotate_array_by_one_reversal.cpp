/*
------------------------------------------------------------
Problem:
Given an array, rotate it clockwise by one position.

Solution Type:
Optimal

Approach: Reversal Algorithm

Logic:
- Reverse the first (n-1) elements.
- Reverse the entire array.
- The last element automatically moves to the front.

Example:
Input:
[1,2,3,4,5]

Reverse first n-1 elements:
[4,3,2,1,5]

Reverse whole array:
[5,1,2,3,4]

Output:
[5,1,2,3,4]

Time Complexity:
O(n)

Space Complexity:
O(1)
------------------------------------------------------------
*/

class Solution {
public:
    void rotate(vector<int> &arr) {

        int n = arr.size();

        // Reverse first n-1 elements
        for (int i = 0, j = n - 2; i < j; i++, j--) {
            swap(arr[i], arr[j]);
        }

        // Reverse the entire array
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            swap(arr[i], arr[j]);
        }
    }
};