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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head) return head;
        
        ListNode *have_k_ele = head;
        for(int i = 0; i < k; i++){
            if(have_k_ele == NULL) return head;
            have_k_ele = have_k_ele->next;
        }
        
        ListNode *prev = NULL, *next = NULL, *curr = head;
        int cnt = 0;
        
        while(curr && cnt < k){
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if(next){
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};