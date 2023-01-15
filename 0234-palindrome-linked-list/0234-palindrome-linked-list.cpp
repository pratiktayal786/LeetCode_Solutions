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
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
    
        ListNode *prev = NULL;
        while(slow){
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        while(head && prev){
            if(head->val == prev->val){
                head = head->next;
                prev = prev->next;
            }
            else return false;
        }
        return true;
    }
};