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
        ListNode* dummy = new ListNode(-1);
        bool isCarry = false;
        ListNode* temp = dummy;
        while(l1 && l2){
            int sum = l1->val + l2->val + (isCarry?1:0);
            temp->next = new ListNode(sum%10);
            if(sum >9)isCarry = true;
            else isCarry = false;

            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        while(l1){
            int sum = l1->val + (isCarry?1:0);
            if(sum >9)isCarry = true;
            else isCarry = false;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + (isCarry?1:0);
            if(sum >9)isCarry = true;
            else isCarry = false;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            l2 = l2->next;
        }
        if(isCarry){
            temp->next = new ListNode(1);
        }
        return dummy->next;
    }
};
