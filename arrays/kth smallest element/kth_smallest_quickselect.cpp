/*
------------------------------------------------------------
Problem:
Given an array arr and an integer k, return the kth smallest
element in the array.

Approach: Quick Select

Logic:
- Select the last element as the pivot.
- Partition the array so elements smaller than the pivot are on
  the left and larger elements are on the right.
- If the pivot reaches index k-1, return it.
- Otherwise recursively search only the required partition.

Example:
Input:
arr = [7, 10, 4, 3, 20, 15], k = 3

Step-by-step:
Partition until pivot reaches index 2.

Output:
7

Time Complexity:
Average: O(n)
Worst: O(n²)

Space Complexity:
Average: O(log n)
(Recursive call stack)
------------------------------------------------------------
*/

class Solution {
private:
    // Partition the array around the pivot
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }

        swap(arr[i], arr[right]);
        return i;
    }

    // Recursively search only the required partition
    int quickSelect(vector<int>& arr, int left, int right, int k) {

        if (left <= right) {

            int pivotIdx = partition(arr, left, right);

            if (pivotIdx == k)
                return arr[pivotIdx];

            if (pivotIdx > k)
                return quickSelect(arr, left, pivotIdx - 1, k);

            return quickSelect(arr, pivotIdx + 1, right, k);
        }

        return -1;
    }

public:
    int kthSmallest(vector<int>& arr, int k) {

        return quickSelect(arr, 0, arr.size() - 1, k - 1);
    }
};