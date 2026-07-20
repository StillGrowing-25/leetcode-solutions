# 203. Remove Linked List Elements

🔗 **Problem Link:** https://leetcode.com/problems/remove-linked-list-elements/

## Solution
# Intuition
Traverse the linked list once while keeping track of the previous valid node. Whenever a node with the target value is found, skip it by updating the previous node's `next` pointer. A dummy node is used to handle cases where the head itself needs to be removed.

# Approach
- Create a dummy node whose `next` points to the head.
- Maintain two pointers:
  - `a` → points to the last node that is not removed.
  - `temp` → traverses the linked list.
- For each node:
  - If its value equals `val`, link `a->next` to `temp->next`, effectively removing the node.
  - Otherwise, move `a` forward to the current node.
- Continue until the end of the list.
- Return `dummy.next` as the new head.

# Complexity
- Time complexity:
  - **O(n)**, where `n` is the number of nodes in the linked list.

- Space complexity:
  - **O(1)**, as only a few pointers are used.

# Code
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode* a = &dummy;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (temp->val == val) {
                a->next = temp->next;
            } else {
                a = temp;
            }
            temp = temp->next;
        }

        return dummy.next;
    }
};
