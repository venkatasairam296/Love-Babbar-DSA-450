/*
------------------------------------------------------------
Problem:
Given a collection of intervals, merge all overlapping intervals
and return a list of non-overlapping intervals covering all the
intervals.

Solution Type:
Brute Force

Approach: Sorting + Check Every Possible Overlap

Logic:
- Sort the intervals based on their starting time.
- Traverse each interval one by one.
- Skip an interval if it is already completely covered by the
  previously merged interval.
- Otherwise, compare it with every following interval.
- If the next interval overlaps with the current one, extend the
  ending point.
- Store the merged interval in the result.

Example:
Input:
[[1,3],[2,4],[6,8],[7,9]]

Sorted:
[[1,3],[2,4],[6,8],[7,9]]

Merge:
[1,3] + [2,4] -> [1,4]
[6,8] + [7,9] -> [6,9]

Output:
[[1,4],[6,9]]

Time Complexity:
O(n²)
- Every interval may compare with all remaining intervals.

Space Complexity:
O(n)
- Extra space is used to store the merged intervals.
------------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

        int n = arr.size();

        // Sort intervals by starting time
        sort(arr.begin(), arr.end());

        vector<vector<int>> res;

        // Check every interval
        for (int i = 0; i < n; i++) {

            int start = arr[i][0];
            int end = arr[i][1];

            // Skip intervals already covered by the previous merge
            if (!res.empty() && res.back()[1] >= end) {
                continue;
            }

            // Extend the current interval while overlaps exist
            for (int j = i + 1; j < n; j++) {
                if (arr[j][0] <= end) {
                    end = max(end, arr[j][1]);
                }
            }

            res.push_back({start, end});
        }

        return res;
    }
};
