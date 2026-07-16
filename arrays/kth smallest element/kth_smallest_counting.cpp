/*
------------------------------------------------------------
Problem:
Given an array arr and an integer k, return the kth smallest
element in the array.

Approach: Counting / Frequency Array

Logic:
- Find the maximum element in the array.
- Create a frequency array of size maxElement + 1.
- Count the occurrence of every element.
- Traverse the frequency array while maintaining the cumulative
  count.
- When the cumulative count becomes at least k, that index is the
  kth smallest element.

Example:
Input:
arr = [7, 10, 4, 3, 20, 15], k = 3

Frequency:
3 -> 1
4 -> 1
7 -> 1

Cumulative Count:
3 -> 1
4 -> 2
7 -> 3

Output:
7

Time Complexity:
O(n + M)
where M is the maximum element in the array.

Space Complexity:
O(M)
------------------------------------------------------------
*/

class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {

        int maxEl = INT_MIN;

        // Find the maximum element
        for (int num : arr) {
            maxEl = max(maxEl, num);
        }

        // Store the frequency of each element
        vector<int> freq(maxEl + 1, 0);

        for (int num : arr) {
            freq[num]++;
        }

        int count = 0;

        // Find the kth smallest element
        for (int i = 0; i <= maxEl; i++) {

            if (freq[i] > 0) {
                count += freq[i];

                if (count >= k) {
                    return i;
                }
            }
        }

        return -1;
    }
};