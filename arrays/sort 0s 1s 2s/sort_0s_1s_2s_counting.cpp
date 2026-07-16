/*
------------------------------------------------------------
Problem:
Given an array consisting only of 0s, 1s, and 2s, sort the array.

Approach: Counting

Logic:
- Count the number of 0s, 1s, and 2s.
- Overwrite the array:
  - Fill all 0s.
  - Then all 1s.
  - Finally all 2s.

Example:
Input:
arr = [2, 0, 1, 2, 0]

Step-by-step:
Count:
0s = 2
1s = 1
2s = 2

Rebuild array:
[0, 0, 1, 2, 2]

Output:
[0, 0, 1, 2, 2]

Time Complexity:
O(n)

Space Complexity:
O(1)
------------------------------------------------------------
*/

class Solution {
public:
    void sort012(vector<int>& arr) {
        int n = arr.size();

        int c0 = 0, c1 = 0, c2 = 0;

        // Count the occurrences of 0s, 1s, and 2s
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                c0++;
            else if (arr[i] == 1)
                c1++;
            else
                c2++;
        }

        int i = 0;

        // Fill the array with 0s
        while (c0--) {
            arr[i++] = 0;
        }

        // Fill the array with 1s
        while (c1--) {
            arr[i++] = 1;
        }

        // Fill the array with 2s
        while (c2--) {
            arr[i++] = 2;
        }
    }
};