/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) return NULL;
        
        int l1 = 0, l2 = 0;
        ListNode *p1 = headA, *p2 = headB;
        
        while(p1){
            l1++;
            p1 = p1->next;
        }
        while(p2){
            l2++;
            p2 = p2->next;
        }
        int diff = abs(l1-l2);
        p1 = headA, p2 = headB;
        
        if(l1 > l2){
            while(diff--){
                p1 = p1->next;
            }
        }
        else{
            while(diff--){
                p2 = p2->next;
            }
        }
        
        while(p1 && p2){
            if(p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};