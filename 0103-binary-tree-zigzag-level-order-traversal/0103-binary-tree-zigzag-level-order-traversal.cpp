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
    void levelOrder(TreeNode *root, vector<vector<int>> &ans){
        
        if(!root) return;
        
        int flag = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> vec;
            int n = q.size();
            while(n--){
                TreeNode *temp = q.front();
                q.pop();
                vec.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(!flag){
                ans.push_back(vec);
                flag = 1;
            }
            else{
                reverse(vec.begin(), vec.end());
                ans.push_back(vec);
                flag = 0;
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, ans);
        return ans;
    }
};