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
        
        ListNode *dum = new ListNode();
        ListNode *head = dum;
        int car = 0;
        
        while(l1 || l2 || car){
            
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            if(car){
                sum += car;
            }
            car =  sum/10;
            dum->next = new ListNode(sum%10);
            dum = dum->next;
        }
        return head->next;
    }
};