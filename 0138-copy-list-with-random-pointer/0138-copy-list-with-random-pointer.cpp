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
        
        unordered_map<Node*, int> oriMap;
        Node *temp = head;
        int ind = 0;
        while(temp){
            oriMap[temp] = ind++;
            temp = temp->next;
        }
        
        Node *copyHead = NULL;
        Node *cur = copyHead;
        unordered_map<int, Node*> copyMap;
        temp = head;
        ind = 0;
        
        while(temp){
            Node *t = new Node(temp->val);
            if(copyHead == NULL){
                copyHead = t;
                cur = t;
            }
            else{
                cur->next = t;
                cur = cur->next;
            }
            copyMap[ind++] = cur;
            temp = temp->next;
        }
        
        temp = head;
        cur = copyHead;
        while(temp){
            
            if(temp->random == NULL) cur->random = NULL;
            else cur->random = copyMap[oriMap[temp->random]];
            cur = cur->next;
            temp = temp->next;
        }
        return copyHead;
    }
};