# Intuition

The digits in the linked lists are stored in **forward order**, so we cannot directly add them from the beginning.

A stack allows us to access the digits from the **least significant digit** first. We can push the values of both linked lists into separate stacks, then pop them one by one and perform addition just like normal arithmetic.

The result is constructed from the front by inserting each newly calculated digit at the head.

---

# Approach

1. Traverse `l1` and push all its values into `s1`.
2. Traverse `l2` and push all its values into `s2`.
3. Initialize `carry = 0`.
4. While either stack is not empty:
   - Start with the current `carry`.
   - Add the top value from `s1`, if available.
   - Add the top value from `s2`, if available.
   - Calculate:
     - `carry = sum / 10`
     - Current digit = `sum % 10`
5. Create a new node for the current digit.
6. Insert the new node at the **front** of the result list.
7. After both stacks are empty, add the remaining `carry` if it exists.
8. Return the head of the resulting linked list.

---

# Complexity

Let `n` be the length of `l1` and `m` be the length of `l2`.

- **Time complexity:** `O(n + m)`
  - Traversing both lists: `O(n + m)`
  - Processing both stacks: `O(n + m)`

- **Space complexity:** `O(n + m)`
  - Two stacks store the digits.
  - The result list requires `O(n + m)` nodes in the worst case.

---

# Code

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        ListNode* head = nullptr;
        int carry = 0;

        // Store digits of l1
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Store digits of l2
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        // Add digits from right to left
        while (!s1.empty() || !s2.empty()) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;
            sum = sum % 10;

            ListNode* newNode = new ListNode(sum);
            newNode->next = head;
            head = newNode;
        }

        // Add remaining carry
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
```
