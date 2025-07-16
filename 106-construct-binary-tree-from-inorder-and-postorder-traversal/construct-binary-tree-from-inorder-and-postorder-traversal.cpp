class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start,
                    int end, int& idx, unordered_map<int, int>& inMap) {
        if (start > end) {
            return NULL;
        }

        int rootval = postorder[idx--];
        TreeNode* root = new TreeNode(rootval);

        int i = inMap[rootval];
        root->right = solve(inorder, postorder, i + 1, end, idx, inMap);
        root->left = solve(inorder, postorder, start, i - 1, idx, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int, int> inMap;

        for (int i = 0; i < n; ++i) {
            inMap[inorder[i]] = i;
        }

        int idx = n - 1;
        return solve(inorder, postorder, 0, n - 1, idx, inMap);
    }
};
