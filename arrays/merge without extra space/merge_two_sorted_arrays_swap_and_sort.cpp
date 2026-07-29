/*
------------------------------------------------------------
Problem:
Given two sorted arrays a[] and b[], merge them without using
any extra space so that both arrays remain sorted.

Solution Type:
Better

Approach: Swap + Sort

Logic:
- Compare the largest element of the first array with the
  smallest element of the second array.
- Swap them whenever necessary.
- Continue until all misplaced elements are exchanged.
- Finally, sort both arrays individually.

Example:
Input:
a = [1, 5, 9, 10, 15, 20]
b = [2, 3, 8, 13]

After swaps:
a = [1, 5, 9, 10, 3, 2]
b = [15, 20, 8, 13]

Sort both arrays:

a = [1, 2, 3, 5, 9, 10]
b = [8, 13, 15, 20]

Output:
a = [1, 2, 3, 5, 9, 10]
b = [8, 13, 15, 20]

Time Complexity:
O((n + m) log(n + m))

Space Complexity:
O(1)
------------------------------------------------------------
*/

class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {

        int n = a.size();
        int m = b.size();

        int i = n - 1;
        int j = 0;

        // Swap misplaced elements
        while (i >= 0 && j < m && a[i] > b[j]) {
            swap(a[i--], b[j++]);
        }

        // Restore sorted order
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};