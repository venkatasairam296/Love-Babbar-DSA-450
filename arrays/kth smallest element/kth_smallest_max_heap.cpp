/*
------------------------------------------------------------
Problem:
Given an array arr and an integer k, return the kth smallest
element in the array.

Approach: Max Heap

Logic:
- Create a max heap.
- Insert every element into the heap.
- If the heap size exceeds k, remove the largest element.
- After processing all elements, the heap contains the k smallest
  elements.
- The top of the heap is the kth smallest element.

Example:
Input:
arr = [7, 10, 4, 3, 20, 15], k = 3

Step-by-step:
Heap after processing:
{7, 4, 3}

Top of heap = 7

Output:
7

Time Complexity:
O(n log k)

Space Complexity:
O(k)
------------------------------------------------------------
*/

class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {

        priority_queue<int> maxHeap;

        // Maintain only the k smallest elements
        for (int num : arr) {
            maxHeap.push(num);

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        return maxHeap.top();
    }
};