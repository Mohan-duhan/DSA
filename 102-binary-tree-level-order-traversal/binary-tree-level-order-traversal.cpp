/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void level_Order(TreeNode* root, int lev, vector<vector<int>>& res) {
        if (root == NULL)
            return;

        if (res.size() <= lev)
            res.push_back({});

        res[lev].push_back(root->val);

        level_Order(root->left, lev + 1, res);
        level_Order(root->right, lev + 1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        level_Order(root, 0, res);
        return res;
    }
};