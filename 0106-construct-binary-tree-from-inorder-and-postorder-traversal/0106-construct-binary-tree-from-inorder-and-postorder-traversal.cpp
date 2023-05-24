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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size()-1;
        int rootInd = n;
        return build(inorder, postorder, rootInd, 0, n); 
    }
    
    TreeNode *build(vector<int>& inorder, vector<int>& postorder, int &rootInd, int left, int right){
        if(left > right || rootInd < 0) return NULL;
        int pivot = left;
        while(inorder[pivot] != postorder[rootInd]) pivot++;
        rootInd--;
        TreeNode *root = new TreeNode(inorder[pivot]);
        root->right = build(inorder, postorder, rootInd, pivot+1, right);
        root->left = build(inorder, postorder, rootInd, left, pivot-1);
        return root;
    }
};