/*
------------------------------------------------------------
Problem:
Given a string s, return its reverse.

Approach: Two Pointers

Logic:
- Initialize two pointers:
  - left at the beginning of the string.
  - right at the end of the string.
- Swap the characters at both pointers.
- Move left forward and right backward.
- Continue until both pointers meet or cross.
- Since the string is modified in place, return the updated string.

Example:
Input:
s = "hello"

Step-by-step:
Initial: h e l l o
Swap h and o -> o e l l h
Swap e and l -> o l l e h
Pointers meet -> Stop

Output:
"olleh"

Time Complexity:
O(n)

Space Complexity:
O(1)
- The reversal is performed in-place without using extra space.
------------------------------------------------------------
*/

class Solution {
public:
    string reverseString(string& s) {
        int n = s.length();

        int left = 0, right = n - 1;

        // Reverse the string by swapping characters from both ends
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }

        return s;
    }
};