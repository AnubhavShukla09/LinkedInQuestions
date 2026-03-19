class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        // Base case:
        // If tree is empty OR we've reached the leftmost node,
        // this node becomes the new root after transformation
        if(!root || !root->left) return root;
        // Recursively go to the leftmost node
        // This will eventually return the new root of the flipped tree
        TreeNode* newRoot = upsideDownBinaryTree(root->left);
        // At this point, root->left is the "parent" in the flipped structure
        // We rewire pointers as follows:
        // 1. Original right child becomes the new left child
        root->left->left = root->right;
        // 2. Original root becomes the new right child
        root->left->right = root;
        // Important: break original connections to avoid cycles
        root->left = nullptr;
        root->right = nullptr;
        // Always return the new root found at the bottom
        return newRoot;
    }
};
