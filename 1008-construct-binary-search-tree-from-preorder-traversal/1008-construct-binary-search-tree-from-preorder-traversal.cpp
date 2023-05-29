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
    
//       int i = 0;
//     TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
//         if (i == A.size() || A[i] > bound) return NULL;
//         TreeNode* root = new TreeNode(A[i++]);
//         root->left = bstFromPreorder(A, root->val);
//         root->right = bstFromPreorder(A, bound);
//         return root;
//     }
    
    TreeNode *solve(vector<int> &vec, int i, int j){
        if(i > j) return NULL;
        TreeNode *root = new TreeNode(vec[i]);
        if(i == j) return root;
        int k = i+1;
        for(k; k <= j; k++){
            if(vec[k] > vec[i]) break;
        }
        root->left = solve(vec, i+1, k-1);
        root->right = solve(vec, k, j);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, 0, preorder.size()-1);
    }
};