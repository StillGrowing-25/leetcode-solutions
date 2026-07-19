# 206. Reverse Linked List

**Problem Link:** https://leetcode.com/problems/reverse-linked-list/

## Intuition
To reverse a linked list, we need to change the direction of each node's `next` pointer. By maintaining pointers to the previous, current, and next nodes, we can reverse the links in a single traversal without using any extra space.

## Approach
- Initialize three pointers:
  - `prev` as `NULL`
  - `curr` as `head`
  - `next` as `NULL`
- Traverse the linked list until `curr` becomes `NULL`:
  - Store the next node in `next`.
  - Reverse the current node's link by pointing it to `prev`.
  - Move `prev` to `curr`.
  - Move `curr` to `next`.
- After the traversal, `prev` points to the new head of the reversed linked list.
- Return `prev`.

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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};
```
