/*
------------------------------------------------------------
Problem:
Given an array arr, return the minimum and maximum elements
present in the array.

Approach: Linear Scan

Logic:
- Initialize:
  - minNum with INT_MAX.
  - maxNum with INT_MIN.
- Traverse the array once.
- For each element:
  - Update minNum if the current element is smaller.
  - Update maxNum if the current element is larger.
- Return the minimum and maximum values.

Example:
Input:
arr = [3, 2, 1, 5, 4]

Step-by-step:
- Start:
  minNum = INT_MAX
  maxNum = INT_MIN

- Read 3 -> min = 3, max = 3
- Read 2 -> min = 2, max = 3
- Read 1 -> min = 1, max = 3
- Read 5 -> min = 1, max = 5
- Read 4 -> min = 1, max = 5

Output:
[1, 5]

Time Complexity:
O(n)
- The array is traversed only once.

Space Complexity:
O(1)
- Only two extra variables are used.
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> getMinMax(vector<int>& arr) {
        int minNum = INT_MAX;
        int maxNum = INT_MIN;

        // Traverse the array once to find both minimum and maximum
        for (int i = 0; i < arr.size(); i++) {
            minNum = min(minNum, arr[i]);
            maxNum = max(maxNum, arr[i]);
        }

        return {minNum, maxNum};
    }
};