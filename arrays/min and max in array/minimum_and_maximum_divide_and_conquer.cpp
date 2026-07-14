/*
------------------------------------------------------------
Problem:
Given an array arr, return the minimum and maximum elements
present in the array.

Approach: Divide and Conquer

Logic:
- Divide the array into two halves recursively.
- Base Case 1:
  - If only one element exists, it is both the minimum and maximum.
- Base Case 2:
  - If two elements exist, compare them once to determine the
    minimum and maximum.
- Recursively find the minimum and maximum of the left half.
- Recursively find the minimum and maximum of the right half.
- Combine the results:
  - Overall minimum = min(left minimum, right minimum)
  - Overall maximum = max(left maximum, right maximum)

Example:
Input:
arr = [3, 5, 1, 8, 2]

Step-by-step:
- Divide into:
  Left  = [3, 5, 1]
  Right = [8, 2]

- Left result:
  Min = 1, Max = 5

- Right result:
  Min = 2, Max = 8

- Combine:
  Min = min(1, 2) = 1
  Max = max(5, 8) = 8

Output:
[1, 8]

Time Complexity:
O(n)
- Every element is processed exactly once during recursion.

Space Complexity:
O(log n)
- Due to the recursion call stack.
------------------------------------------------------------
*/

class Solution {
private:
    // Recursively finds the minimum and maximum in the range [low, high]
    vector<int> minMax(vector<int>& arr, int low, int high) {
        vector<int> res(2);

        // Base case: Only one element
        if (low == high) {
            res[0] = res[1] = arr[low];
            return res;
        }

        // Base case: Two elements
        if (high == low + 1) {
            if (arr[low] <= arr[high]) {
                res[0] = arr[low];
                res[1] = arr[high];
            } else {
                res[0] = arr[high];
                res[1] = arr[low];
            }

            return res;
        }

        // Divide the array into two halves
        int mid = (low + high) / 2;

        vector<int> left = minMax(arr, low, mid);
        vector<int> right = minMax(arr, mid + 1, high);

        // Combine the results from both halves
        res[0] = min(left[0], right[0]);
        res[1] = max(left[1], right[1]);

        return res;
    }

public:
    vector<int> getMinMax(vector<int>& arr) {

        // Find the minimum and maximum of the entire array
        return minMax(arr, 0, arr.size() - 1);
    }
};