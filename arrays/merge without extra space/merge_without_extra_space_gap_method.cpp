/*
------------------------------------------------------------
Problem:
Merge two sorted arrays without using extra space.

Solution Type:
Optimal

Approach: Gap Method (Shell Sort Technique)

Logic:
- Consider both arrays as one virtual array.
- Start with a gap equal to half of the total length.
- Compare elements separated by the gap.
- Swap if they are out of order.
- Reduce the gap until it becomes 1.
- Arrays become completely merged and sorted.

Example:
Input:
a = [1,5,9,10]
b = [2,3,8]

Gap comparisons eventually produce:

a = [1,2,3,5]
b = [8,9,10]

Output:
a = [1,2,3,5]
b = [8,9,10]

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

        // Initial gap
        int gap = (n + m + 1) / 2;

        while (gap > 0) {

            int i = 0;
            int j = gap;

            while (j < n + m) {

                // Both pointers in first array
                if (j < n && a[i] > a[j]) {
                    swap(a[i], a[j]);
                }

                // One pointer in each array
                else if (i < n && j >= n && a[i] > b[j - n]) {
                    swap(a[i], b[j - n]);
                }

                // Both pointers in second array
                else if (i >= n && b[i - n] > b[j - n]) {
                    swap(b[i - n], b[j - n]);
                }

                i++;
                j++;
            }

            // Stop after processing gap = 1
            if (gap == 1)
                break;

            // Compute next gap
            gap = (gap + 1) / 2;
        }
    }
};