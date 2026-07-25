/*
------------------------------------------------------------
Problem:
Given an array representing the heights of towers and an integer k,
increase or decrease the height of every tower by exactly k once.
The height of a tower cannot become negative.

Return the minimum possible difference between the tallest and
shortest towers after the modification.

Solution Type:
Optimal

Approach: Sorting + Greedy

Logic:
- Sort the array so the smallest and largest heights are easy to track.
- Initially, the answer is the difference between the maximum and
  minimum heights.
- Consider every element as the dividing point:
    • Towers before the current index are increased by k.
    • Towers from the current index onwards are decreased by k.
- Skip cases where decreasing a tower makes its height negative.
- Compute the new minimum and maximum heights after modification.
- Update the minimum possible difference.

Example:
Input:
arr = [1, 5, 8, 10]
k = 2

Sorted:
[1, 5, 8, 10]

Partition at index 2:
Increase:
[3, 7]

Decrease:
[6, 8]

Minimum = 3
Maximum = 8

Difference = 5

Output:
5

Time Complexity:
O(n log n)
- Sorting takes O(n log n).
- Single traversal takes O(n).

Space Complexity:
O(1)
- No extra space is used (excluding the sorting algorithm).
------------------------------------------------------------
*/

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {

        int n = arr.size();

        // Sort the heights
        sort(arr.begin(), arr.end());

        int minel = arr[0];
        int maxel = arr[n - 1];

        // Initial difference without any modification
        int res = maxel - minel;

        // Try every possible partition
        for (int i = 1; i < n; i++) {

            // Height cannot become negative
            if (arr[i] - k < 0) {
                continue;
            }

            // Possible minimum height
            minel = min(arr[0] + k, arr[i] - k);

            // Possible maximum height
            maxel = max(arr[i - 1] + k, arr[n - 1] - k);

            // Update minimum difference
            res = min(res, maxel - minel);
        }

        return res;
    }
};