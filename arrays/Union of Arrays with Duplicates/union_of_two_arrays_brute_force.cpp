/*
------------------------------------------------------------
Problem:
Given two arrays a and b, return the union of both arrays.
The union should contain only distinct elements.

Solution Type:
Brute Force

Approach: Linear Search

Logic:
- Copy all elements from both arrays into a temporary array.
- Traverse each element of the temporary array.
- For every element, linearly search the result array.
- If the element is not already present, add it to the result.

Example:
Input:
a = [1, 2, 3]
b = [2, 3, 4]

Step-by-step:
Combined array:
[1, 2, 3, 2, 3, 4]

Unique elements:
[1, 2, 3, 4]

Output:
[1, 2, 3, 4]

Time Complexity:
O((n + m)²)

Space Complexity:
O(n + m)
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {

        vector<int> res;

        // Combine both arrays
        vector<int> temp = a;
        temp.insert(temp.end(), b.begin(), b.end());

        // Add only unique elements
        for (int x : temp) {
            bool found = false;

            for (int y : res) {
                if (x == y) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                res.push_back(x);
            }
        }

        return res;
    }
};