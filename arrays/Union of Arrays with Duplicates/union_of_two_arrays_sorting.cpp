/*
------------------------------------------------------------
Problem:
Given two arrays a and b, return the union of both arrays.

Solution Type:
Better

Approach: Sorting

Logic:
- Merge both arrays.
- Sort the combined array.
- Traverse once and keep only distinct elements.

Example:
Input:
a = [1, 2, 3]
b = [2, 3, 4]

Merged:
[1, 2, 3, 2, 3, 4]

Sorted:
[1, 2, 2, 3, 3, 4]

Unique:
[1, 2, 3, 4]

Output:
[1, 2, 3, 4]

Time Complexity:
O((n + m) log(n + m))

Space Complexity:
O(n + m)
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {

        vector<int> res;

        // Merge both arrays
        vector<int> temp = a;
        temp.insert(temp.end(), b.begin(), b.end());

        // Sort merged array
        sort(temp.begin(), temp.end());

        // First element is always unique
        res.push_back(temp[0]);

        // Add only distinct elements
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] != temp[i - 1]) {
                res.push_back(temp[i]);
            }
        }

        return res;
    }
};