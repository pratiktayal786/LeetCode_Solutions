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
        
        ListNode *node = head, *uptoN = head;
        
        for(int i = 0; i < n; i++) node = node->next;
        
        if(node == NULL) return head->next;
        
        while(node->next){
            node = node->next;
            uptoN = uptoN->next;
        }
        uptoN->next = uptoN->next->next;
        return head;
    }
};