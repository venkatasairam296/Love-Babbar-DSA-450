/*
------------------------------------------------------------
Problem:
Given two arrays a and b, return the union of both arrays.

Solution Type:
Better

Approach: Set

Logic:
- Insert every element of both arrays into a set.
- Since a set stores only unique values, duplicates are removed.
- Traverse the set and store the result.

Example:
Input:
a = [1, 2, 3]
b = [2, 3, 4]

Set:
{1, 2, 3, 4}

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
        set<int> uni;

        // Insert elements of first array
        for (int x : a) {
            uni.insert(x);
        }

        // Insert elements of second array
        for (int x : b) {
            uni.insert(x);
        }

        // Store unique elements
        for (int x : uni) {
            res.push_back(x);
        }

        return res;
    }
};