/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     unordered_map<TreeNode*, TreeNode*> parent;
     unordered_map<TreeNode*, bool> vis;
     vector<int> ans;
    
     void findParent(TreeNode *node){
        if(node->left){
            parent[node->left] = node;
            findParent(node->left);
        }
        if(node->right){
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
     void dfs(TreeNode *node, int k){
        if(vis[node] == true) return;
        vis[node] = true;
        
        if(k == 0){
            ans.push_back(node->val);
            return;
        }
        if(node->left){
            dfs(node->left, k-1);
        }
        if(node->right){
            dfs(node->right, k-1);
        }
        
        TreeNode *p = parent[node];
        if(p){
            dfs(p, k-1);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        findParent(root);
        dfs(target, k);
        return ans;
    }
    
};