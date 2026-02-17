class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {

        // base case → empty OR leftmost node becomes new root
        if(!root || !root->left) return root;

        // recurse to find new root
        TreeNode* newRoot = upsideDownBinaryTree(root->left);

        // rewire pointers
        root->left->left = root->right; // old right becomes new left
        root->left->right = root;       // old root becomes new right

        // break original links
        root->left = nullptr;
        root->right = nullptr;

        return newRoot;
    }
};
