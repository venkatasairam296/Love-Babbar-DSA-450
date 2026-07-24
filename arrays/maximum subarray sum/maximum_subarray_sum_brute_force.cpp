/*
------------------------------------------------------------
Problem:
Given an array of integers, find the contiguous subarray
having the largest sum and return that maximum sum.

Solution Type:
Brute Force

Approach: Nested Loops

Logic:
- Consider every possible starting index.
- Expand the subarray one element at a time.
- Keep track of the current subarray sum.
- Update the maximum sum whenever a larger sum is found.

Example:
Input:
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Maximum Subarray:
[4, -1, 2, 1]

Output:
6

Time Complexity:
O(n²)

Space Complexity:
O(1)
------------------------------------------------------------
*/

class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {

        int maxSum = arr[0];

        // Generate every possible subarray
        for (int i = 0; i < arr.size(); i++) {

            int currSum = 0;

            for (int j = i; j < arr.size(); j++) {

                currSum += arr[j];

                // Update maximum sum
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};