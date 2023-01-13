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
    
    ListNode* rev(ListNode* head){
        if(!head || !head->next) return head;
        
        ListNode *curr = rev(head->next);
        
        curr->next = head;
        head->next = NULL;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode *temp = head;
        while(temp->next) temp = temp->next;

        rev(head);
        
        return temp;
    }
};  