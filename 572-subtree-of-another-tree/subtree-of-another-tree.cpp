class Solution {
public:
    bool areIdenticals(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL)
            return true;
        if (root == NULL || subRoot == NULL)
            return false;

        return (root->val == subRoot->val) &&
               areIdenticals(root->left, subRoot->left) &&
               areIdenticals(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL)
            return true; 
        if (root == NULL)
            return false;

        if (areIdenticals(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
