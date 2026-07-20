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
        struct ListNode* a = &dummy;
        struct ListNode* temp = head;
        while (temp != NULL) {
            if (temp->val == val) {
                a->next = temp->next;
            }else{
            a = temp;}
            temp = temp->next;
        }
        return dummy.next;
    }
};
