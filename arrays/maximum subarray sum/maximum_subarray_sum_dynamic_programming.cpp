/*
------------------------------------------------------------
Problem:
Given an array of integers, find the contiguous subarray
having the maximum possible sum.

Solution Type:
Optimal

Approach: Dynamic Programming (Kadane's DP Form)

Logic:
- Let subSum represent the maximum subarray ending at
  the current index.
- At every element:
    Either extend the previous subarray
    OR
    Start a new subarray.
- Store the best answer seen so far.

Transition:
subSum = max(subSum + arr[i], arr[i])

Example:
Input:
[-2,1,-3,4,-1,2,1,-5,4]

Output:
6

Time Complexity:
O(n)

Space Complexity:
O(1)
------------------------------------------------------------
*/

class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {

        // Maximum subarray ending at current index
        int subSum = arr[0];

        // Overall answer
        int res = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            // Extend previous subarray or start fresh
            subSum = max(subSum + arr[i], arr[i]);

            // Update global maximum
            res = max(res, subSum);
        }

        return res;
    }
};