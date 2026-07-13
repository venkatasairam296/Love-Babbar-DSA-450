/*
------------------------------------------------------------
Problem:
Given a string s, return its reverse.

Approach: Temporary String (Reverse Traversal)

Logic:
- Create an empty string to store the reversed result.
- Traverse the original string from the last character to the first.
- Append each character to the temporary string.
- Return the temporary string as the reversed string.

Example:
Input:
s = "hello"

Step-by-step:
- Start from the last character: 'o'
- Append characters in reverse order: "o" → "ol" → "oll" → "olle" → "olleh"
- Return the reversed string.

Output:
"olleh"

Time Complexity:
O(n)

Space Complexity:
O(n)
- Extra space is used to store the reversed string.
------------------------------------------------------------
*/

class Solution {
public:
    string reverseString(string& s) {
        int n = s.length();
        string temp = "";

        // Traverse the string from end to beginning
        for (int i = n - 1; i >= 0; i--) {
            temp += s[i];
        }

        return temp;
    }
};