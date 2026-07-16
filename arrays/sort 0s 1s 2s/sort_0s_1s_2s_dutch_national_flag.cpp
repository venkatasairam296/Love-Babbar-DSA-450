/*
------------------------------------------------------------
Problem:
Given an array consisting only of 0s, 1s, and 2s, sort the array.

Approach: Dutch National Flag Algorithm (Three Pointers)

Logic:
- Maintain three pointers:
  - low: next position for 0
  - mid: current element
  - high: next position for 2
- Traverse the array once:
  - If arr[mid] is 0:
      Swap with low, increment both pointers.
  - If arr[mid] is 1:
      Move mid forward.
  - If arr[mid] is 2:
      Swap with high and decrement high.
      Do not increment mid because the swapped element
      needs to be checked.

Example:
Input:
arr = [2, 0, 2, 1, 1, 0]

Step-by-step:
Initial:
low = 0, mid = 0, high = 5

After processing:
[0, 0, 1, 1, 2, 2]

Output:
[0, 0, 1, 1, 2, 2]

Time Complexity:
O(n)

Space Complexity:
O(1)
------------------------------------------------------------
*/

class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;

        // Partition the array into three regions
        while (mid <= high) {

            if (arr[mid] == 0) {
                // Place 0 in the beginning
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                // 1 is already in the correct region
                mid++;
            }
            else {
                // Place 2 at the end
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};