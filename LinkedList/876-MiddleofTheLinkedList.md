# Middle of the Linked List

**Problem Link:** https://leetcode.com/problems/middle-of-the-linked-list/

## Intuition

To find the middle node efficiently, we can use two pointers:

- A **slow pointer** that moves **one step** at a time.
- A **fast pointer** that moves **two steps** at a time.

By the time the fast pointer reaches the end of the linked list, the slow pointer will be exactly at the middle.

If the linked list has an even number of nodes, the problem requires returning the **second middle node**, which this approach naturally does.

## Approach

1. Initialize two pointers, `slow` and `fast`, both pointing to the head.
2. Traverse the linked list while:
   - `fast` is not `nullptr`.
   - `fast->next` is not `nullptr`.
3. Move:
   - `slow` by one node.
   - `fast` by two nodes.
4. When the loop ends, `slow` points to the middle node.
5. Return `slow`.

## Complexity

- **Time Complexity:** `O(n)`
  - The list is traversed only once.

- **Space Complexity:** `O(1)`
  - No extra space is used.

## Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast by 2 steps and slow by 1 step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
```
