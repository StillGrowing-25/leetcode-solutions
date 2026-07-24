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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        struct ListNode* temp = head;
        struct ListNode* x = head;
        struct ListNode* y = head;
        struct ListNode* a;
        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }
        n = (ceil)(n / 2);

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
