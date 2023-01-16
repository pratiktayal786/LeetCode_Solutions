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
        
        ListNode *temp = head;
        int cnt = 0;
        while(temp) ++cnt, temp = temp->next;
        
        if(!head || (cnt == 1 && n == 1)) return NULL;
        cnt -= n;
        
        if(cnt == 0) return head->next;
        
        temp = head;
        int i = 1;
        while(temp->next){
            if(i == cnt) {
                temp->next = temp->next->next;
                break;
            }
            else i++;
            temp = temp->next;
        }
        return head;
    }
};