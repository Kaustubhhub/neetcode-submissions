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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;

        ListNode* first = head, *second = head;

        while(n>0){
            second = second->next;
            n--;
        }

        if(!second)return head->next;

        while(second -> next){
            second = second->next;
            first = first->next;
        }

        first->next = first->next->next;
        return head;
    }
};
