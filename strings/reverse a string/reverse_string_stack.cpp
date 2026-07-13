/*
------------------------------------------------------------
Problem:
Given a string s, return its reverse.

Approach: Stack

Logic:
- Create an empty stack to store the characters of the string.
- Traverse the string and push each character onto the stack.
- Since a stack follows the Last In, First Out (LIFO) principle,
  the characters will come out in reverse order.
- Pop each character from the stack and overwrite the original string.
- Return the reversed string.

Example:
Input:
s = "hello"

Step-by-step:
- Push: h, e, l, l, o
- Stack (Top -> Bottom): o, l, l, e, h
- Pop and place back into the string:
  o -> l -> l -> e -> h

Output:
"olleh"

Time Complexity:
O(n)
- Pushing all characters: O(n)
- Popping all characters: O(n)

Space Complexity:
O(n)
- Extra stack is used to store all characters.
------------------------------------------------------------
*/

class Solution {
public:
    string reverseString(string& s) {
        int n = s.length();

        stack<char> reverse;

        // Push every character onto the stack
        for (char ch : s) {
            reverse.push(ch);
        }

        // Pop characters and overwrite the original string
        for (int i = 0; i < n; i++) {
            s[i] = reverse.top();
            reverse.pop();
        }

        return s;
    }
};