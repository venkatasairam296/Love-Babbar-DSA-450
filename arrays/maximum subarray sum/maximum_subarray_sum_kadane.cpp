/*
------------------------------------------------------------
Problem:
Given an array of integers, find the contiguous subarray
having the largest sum.

Solution Type:
Optimal

Approach: Kadane's Algorithm

Logic:
- Traverse the array while maintaining a running sum.
- Update the maximum sum whenever the running sum increases.
- If the running sum becomes negative, reset it to zero.
- This ensures only beneficial prefixes are carried forward.

Example:
Input:
[-2,1,-3,4,-1,2,1,-5,4]

Running sums:
-2 → reset
1
-2
4
3
5
6

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

        int maxSum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {

            sum += arr[i];

            // Update answer
            maxSum = max(maxSum, sum);

            // Discard negative prefix
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};