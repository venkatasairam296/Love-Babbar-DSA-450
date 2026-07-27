/*
------------------------------------------------------------
Problem:
Given an array of integers, return all elements that appear
more than once in the array.

Solution Type:
Better

Approach: Hash Map (Frequency Counting)

Logic:
- Create an unordered_map to store the frequency of each element.
- Traverse the array and increment the frequency of every element.
- Traverse the hash map and collect elements whose frequency is
  greater than 1.

Example:
Input:
arr = [2, 3, 1, 2, 3]

Frequency Map:
1 -> 1
2 -> 2
3 -> 2

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

        unordered_map<int, int> freq;
        vector<int> res;

        // Count frequency of every element
        for (int num : arr) {
            freq[num]++;
        }

        // Store duplicate elements
        for (auto &entry : freq) {
            if (entry.second > 1) {
                res.push_back(entry.first);
            }
        }

        return res;
    }
};