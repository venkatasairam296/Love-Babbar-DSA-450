/*
------------------------------------------------------------
Problem:
Given an array arr, return the minimum and maximum elements
present in the array.

Approach: Pairwise Comparison

Logic:
- Handle odd and even-sized arrays separately.
- If the array size is odd:
  - Initialize both minimum and maximum with the first element.
  - Start processing from the second element.
- If the array size is even:
  - Compare the first two elements to initialize minimum and maximum.
  - Start processing from the third element.
- Traverse the remaining elements in pairs.
- For each pair:
  - Compare the two elements once.
  - Update the minimum using the smaller element.
  - Update the maximum using the larger element.
- Return the minimum and maximum.

Example:
Input:
arr = [7, 2, 9, 4, 1, 6]

Step-by-step:
- Compare (7, 2) -> min = 2, max = 7
- Compare (9, 4) -> larger = 9, smaller = 4
  min = 2, max = 9
- Compare (1, 6) -> larger = 6, smaller = 1
  min = 1, max = 9

Output:
[1, 9]

Time Complexity:
O(n)
- The array is traversed only once.

Space Complexity:
O(1)
- Only a few extra variables are used.

Note:
- This approach reduces the total number of comparisons.
- It performs approximately 3n/2 comparisons instead of 2n
  comparisons in the simple linear scan approach.
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> getMinMax(vector<int>& arr) {
        int n = arr.size();
        int mini, maxi, i;

        // Initialize minimum and maximum
        if (n % 2 == 1) {
            // Odd number of elements
            mini = maxi = arr[0];
            i = 1;
        } else {
            // Even number of elements
            if (arr[0] < arr[1]) {
                mini = arr[0];
                maxi = arr[1];
            } else {
                mini = arr[1];
                maxi = arr[0];
            }
            i = 2;
        }

        // Process the remaining elements in pairs
        while (i < n - 1) {

            // Compare elements within the pair first
            if (arr[i] <= arr[i + 1]) {
                mini = min(mini, arr[i]);
                maxi = max(maxi, arr[i + 1]);
            } else {
                mini = min(mini, arr[i + 1]);
                maxi = max(maxi, arr[i]);
            }

            i += 2;
        }

        return {mini, maxi};
    }
};