class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        // if both nodes are null
        if(!root1 && !root2) return nullptr;

        // if one node is null → return the other
        if(!root1) return root2;
        if(!root2) return root1;

        // create new node with sum of values
        TreeNode* root = new TreeNode(root1->val + root2->val);

        // recursively merge left and right children
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);

        return root;
    }
};
