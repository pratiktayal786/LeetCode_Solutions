/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        if(!root) return ans;
        TreeNode *cur = root;
        
        while(cur != NULL || !stk.empty()){
            if(cur != NULL){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                TreeNode *temp = stk.top();
                if(temp->right != NULL){
                    cur = temp->right;
                }
                else{
                    ans.push_back(temp->val);
                    stk.pop();
                    while(!stk.empty() && stk.top()->right == temp){
                        temp = stk.top();
                        stk.pop();
                        ans.push_back(temp->val);
                    }
                }
            }
        }
        return ans;
    }
};