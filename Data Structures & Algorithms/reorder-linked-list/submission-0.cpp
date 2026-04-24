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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head, *temp = head, *prev = NULL;

        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || head->next == NULL || head->next->next == NULL)return;
        ListNode* slow = head, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

                ListNode* second = slow->next;
    slow->next = nullptr;  // split the list into two halves
    ListNode* newHead = reverseList(second);

        ListNode* finalHead = head;
        ListNode* temp1 = head, *temp2 = newHead;

        while(head && newHead){
            temp1 = head->next;
            head->next = newHead;
            head = temp1;
            temp2 = newHead->next;
            newHead->next = head;
            newHead = temp2;
        }

        return ;
    }
};
