/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        void traversal(TreeNode *root, int r, int c, vector<pair<int, pair<int, int>>> &v)
        {
            if (!root) return;

            v.push_back({ root->val,
                {
                    r,
                    c
                } });

            traversal(root->left, r + 1, c - 1, v);
            traversal(root->right, r + 1, c + 1, v);
        }
    static bool comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
    {
        if (a.second.second == b.second.second)
        {
            if (a.second.first == b.second.first)
            {
                return a.first < b.first;
            }
            return a.second.first < b.second.first;
        }
        return a.second.second < b.second.second;
    }
    vector<vector < int>> verticalTraversal(TreeNode *root)
    {

        vector<vector < int>> ans;
        vector<pair<int, pair<int, int>>> v;
        if (!root) return ans;
        traversal(root, 0, 0, v);
        sort(v.begin(), v.end(), comp);
        vector<int> temp;
        temp.push_back(v[0].first);
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].second.second != v[i - 1].second.second)
            {
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(v[i].first);
        }
        if (!temp.empty())
        {
            ans.push_back(temp);
        }
        return ans;
    }
};