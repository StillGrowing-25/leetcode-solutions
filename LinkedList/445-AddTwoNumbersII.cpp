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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        struct ListNode* head = nullptr;
        int sum = 0;
        int carry = 0;

        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

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
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
    return head;
    }
};
