# 141. Linked List Cycle

**Problem Link:** https://leetcode.com/problems/linked-list-cycle/

## Intuition
Instead of storing visited nodes, we can use two pointers moving at different speeds. If the linked list contains a cycle, the faster pointer will eventually catch up with the slower pointer. If there is no cycle, the fast pointer will reach the end of the list.

## Approach
- Initialize two pointers:
  - `slow` moves one node at a time.
  - `fast` moves two nodes at a time.
- Traverse the linked list while both `fast` and `fast->next` are not `NULL`.
- Move:
  - `slow = slow->next`
  - `fast = fast->next->next`
- If `slow` and `fast` meet at any point, a cycle exists, so return `true`.
- If the traversal ends, no cycle exists, so return `false`.

## Complexity
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

## Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Floyd's Tortoise and Hare Algorithm
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};
```
