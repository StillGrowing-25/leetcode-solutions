# LeetCode 142: Linked List Cycle II

## Problem Link
https://leetcode.com/problems/linked-list-cycle-ii/

## Intuition
A brute-force approach would require storing visited nodes in a hash set, which uses extra memory.

A more optimal solution is Floyd's Cycle Detection Algorithm (Tortoise and Hare). Two pointers move through the linked list at different speeds. If they meet, a cycle exists. After the meeting point, resetting one pointer to the head and moving both pointers one step at a time will make them meet again at the starting node of the cycle.

## Approach
1. Initialize two pointers, `slow` and `fast`, at the head.
2. Move `slow` by one step and `fast` by two steps.
3. If they never meet, there is no cycle, so return `NULL`.
4. If they meet:
   - Reset `slow` to the head.
   - Move both pointers one step at a time.
   - The node where they meet is the starting node of the cycle.
5. Return the starting node.

## Why Does It Work?
Suppose:
- Distance from head to cycle start = **x**
- Distance from cycle start to meeting point = **y**
- Remaining cycle length = **z**

When the pointers meet:
- Slow travels: `x + y`
- Fast travels: `x + y + k(y + z)` for some integer `k`

Since the fast pointer moves twice as fast:

`2(x + y) = x + y + k(y + z)`

Simplifying:

`x = k(y + z) - y`

This means the distance from the head to the cycle start equals the distance from the meeting point to the cycle start. Therefore, moving both pointers one step at a time makes them meet exactly at the cycle's starting node.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};
```
