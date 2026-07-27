/*
------------------------------------------------------------
Problem:
Given an array of integers, return all elements that appear
more than once in the array.

Solution Type:
Optimal

Approach: Frequency Array

Logic:
- Create a frequency array of size n+1.
- Traverse the input array and count occurrences.
- Traverse the frequency array.
- Every index with frequency greater than 1 is a duplicate.

Example:
Input:
arr = [2, 3, 1, 2, 3]

Frequency Array:
Index : 0 1 2 3 4 5
Count : 0 1 2 2 0 0

Output:
[2, 3]

Time Complexity:
O(n)

Space Complexity:
O(n)
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {

        int n = arr.size();

        vector<int> freq(n + 1, 0);
        vector<int> res;

        // Count occurrences
        for (int num : arr) {
            freq[num]++;
        }

        // Collect duplicates
        for (int i = 0; i <= n; i++) {
            if (freq[i] > 1) {
                res.push_back(i);
            }
        }

        return res;
    }
};