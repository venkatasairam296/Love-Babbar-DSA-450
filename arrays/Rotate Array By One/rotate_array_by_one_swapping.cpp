/*
------------------------------------------------------------
Problem:
Given an array, rotate it clockwise by one position.

Solution Type:
Better

Approach: Repeated Swapping

Logic:
- Keep the last element fixed.
- Swap it with every previous element.
- After all swaps, the last element reaches index 0.

Example:
Input:
[1, 2, 3, 4, 5]

Swap(1,5)
[5,2,3,4,1]

Swap(2,1)
[5,1,3,4,2]

Swap(3,2)
[5,1,2,4,3]

Swap(4,3)
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

        int i = 0;
        int j = arr.size() - 1;

        // Move the last element to the front using swaps
        while (i != j) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
};