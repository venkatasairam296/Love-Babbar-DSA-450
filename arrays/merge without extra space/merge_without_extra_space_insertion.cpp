/*
------------------------------------------------------------
Problem:
Given two sorted arrays, merge them such that after merging:
- The first array contains the first n smallest elements.
- The second array contains the remaining m largest elements.
- Do not use any extra space.

Solution Type:
Better

Approach: Insertion-Based In-place Merge

Logic:
- Traverse the second array from right to left.
- Compare the current element with the last element of the first array.
- If the current element is smaller:
    • Store the last element of the first array.
    • Shift larger elements in the first array one position to the right.
    • Insert the current element into its correct position.
    • Replace the current element in the second array with the stored value.
- Repeat until both arrays become correctly partitioned.

Example:
Input:
a = [1, 5, 9, 10, 15, 20]
b = [2, 3, 8, 13]

After processing:
a = [1, 2, 3, 5, 8, 9]
b = [10, 13, 15, 20]

Output:
a = [1, 2, 3, 5, 8, 9]
b = [10, 13, 15, 20]

Time Complexity:
O(n × m) (Worst Case)

Space Complexity:
O(1)
------------------------------------------------------------
*/

class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {

        int n = a.size();
        int m = b.size();

        // Traverse the second array from right to left
        for (int i = m - 1; i >= 0; i--) {

            // If the largest element of 'a' is greater,
            // insert the current element of 'b' into 'a'
            if (a[n - 1] > b[i]) {

                int last = a[n - 1];

                int j = n - 2;

                // Shift larger elements to the right
                while (j >= 0 && a[j] > b[i]) {
                    a[j + 1] = a[j];
                    j--;
                }

                // Insert current element into its sorted position
                a[j + 1] = b[i];

                // Move the previous largest element to array 'b'
                b[i] = last;
            }
        }
    }
};