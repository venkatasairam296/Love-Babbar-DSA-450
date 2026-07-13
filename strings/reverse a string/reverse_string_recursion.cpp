/*
------------------------------------------------------------
Problem:
Given a string s, return its reverse.

Approach: Recursion (Two Pointers)

Logic:
- Use two pointers:
  - left starts from the beginning.
  - right starts from the end.
- If left >= right, the string has been completely reversed, so stop the recursion.
- Swap the characters at the left and right pointers.
- Recursively call the function for the remaining inner substring.
- Since the string is passed by reference, all changes are made in-place.

Example:
Input:
s = "hello"

Step-by-step:
Initial: h e l l o

Call 1:
Swap h and o -> o e l l h

Call 2:
Swap e and l -> o l l e h

Call 3:
left == right -> Stop recursion

Output:
"olleh"

Time Complexity:
O(n)
- Each character is visited at most once.

Space Complexity:
O(n)
- Due to the recursive call stack.
------------------------------------------------------------
*/

class Solution {
private:
    // Recursively reverse the string by swapping characters
    void reverseHelper(string& s, int left, int right) {

        // Base case: pointers have met or crossed
        if (left >= right) {
            return;
        }

        // Swap characters at both ends
        swap(s[left], s[right]);

        // Recur for the remaining inner substring
        reverseHelper(s, left + 1, right - 1);
    }

public:
    string reverseString(string& s) {
        int n = s.length();

        // Start reversing from both ends
        reverseHelper(s, 0, n - 1);

        return s;
    }
};