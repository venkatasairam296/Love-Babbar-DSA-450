/*
------------------------------------------------------------
Problem:
Given an array where each element represents the maximum number
of steps that can be jumped forward from that position, find the
minimum number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.

Solution Type:
Optimal

Approach: Greedy

Logic:
- Maintain the farthest index that can be reached (maxReach).
- Maintain the end of the current jump range (currReach).
- Traverse the array while continuously updating maxReach.
- Whenever the current index reaches currReach:
    • A new jump is required.
    • Extend currReach to maxReach.
- If maxReach never moves beyond the current index, the destination
  cannot be reached.
- If maxReach reaches or crosses the last index, return the total
  number of jumps.

Example:
Input:
arr = [2, 3, 1, 1, 4]

Step-by-step:
Start:
maxReach = 0
currReach = 0
jumps = 0

Index 0:
maxReach = 2
Need a jump.
currReach = 2
jumps = 1

Index 1:
maxReach = 4

Since maxReach reaches the last index,
answer = 2.

Output:
2

Time Complexity:
O(n)

Space Complexity:
O(1)
------------------------------------------------------------
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        // If there is only one element, we are already at the destination
        if (n == 1) {
            return 0;
        }

        // Cannot move anywhere
        if (arr[0] == 0) {
            return -1;
        }

        int maxReach = 0;   // Farthest reachable index
        int currReach = 0;  // End of current jump range
        int jumps = 0;

        for (int i = 0; i < n; i++) {

            // Update the farthest reachable position
            maxReach = max(maxReach, i + arr[i]);

            // Destination can be reached
            if (maxReach >= n - 1) {
                return jumps + 1;
            }

            // Need to make another jump
            if (i == currReach) {

                // Cannot move any further
                if (maxReach == i) {
                    return -1;
                }

                jumps++;
                currReach = maxReach;
            }
        }

        return -1;
    }
};