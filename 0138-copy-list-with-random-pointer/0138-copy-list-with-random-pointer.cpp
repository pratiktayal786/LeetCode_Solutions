/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *it = head;
        while(it){
            Node *temp = new Node(it->val);
            temp->next = it->next;
            it->next = temp;
            it = it->next->next;
        }
        
        it = head;
        while(it){
            if(it->random) it->next->random = it->random->next;
            it = it->next->next;
        }
        
        it = head;
        Node *ans = new Node(0);
        Node *helper = ans;
        
        while(it){
            helper->next = it->next;
            it->next = it->next->next;
            helper = helper->next;
            it = it->next;
        }
        return ans->next;
    }
};