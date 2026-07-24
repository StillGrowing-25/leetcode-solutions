# Palindrome Linked List

**Problem Link:** https://leetcode.com/problems/palindrome-linked-list/

---

# Intuition

A linked list is a palindrome if it reads the same from both ends. Since singly linked lists do not allow backward traversal, we can reverse the second half of the list and compare it with the first half.

This approach avoids using extra space such as an array or stack and achieves constant auxiliary space.

---

# Approach

1. Traverse the linked list to calculate its length.
2. Move a pointer to the beginning of the second half of the list.
3. Reverse the second half in-place.
4. Compare the first half with the reversed second half node by node.
5. If any pair of values differs, return `false`; otherwise, return `true`.

---

# Complexity

- **Time complexity:** `O(n)`
  - One traversal to find the length.
  - One traversal to reach the middle.
  - One traversal to reverse the second half.
  - One traversal to compare both halves.

- **Space complexity:** `O(1)`
  - Only a few pointer variables are used.

---

# Code

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        ListNode* x = head;
        ListNode* y = head;
        ListNode* a;

        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }

        n = ceil(n / 2);

        for (int i = 0; i < n; i++) {
            a = y;
            y = y->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = y;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        y = prev;

        while (y != nullptr) {
            if (x->val != y->val) {
                return false;
            }

            x = x->next;
            y = y->next;
        }

        return true;
    }
};
```
