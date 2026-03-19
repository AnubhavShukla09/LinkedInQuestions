class Solution {
public:
    // Helper function to check if two subtrees are mirror images
    bool mirror(TreeNode* left, TreeNode* right){
        // If both nodes are null → symmetric at this level
        if(left == nullptr && right == nullptr)
            return true;
        // If only one is null → not symmetric
        if(left == nullptr || right == nullptr)
            return false;
        // If values don't match → not symmetric
        if(left->val != right->val)
            return false;
        // Recursively check:
        // left's left with right's right (outer symmetry)
        // left's right with right's left (inner symmetry)
        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        // Edge case: empty tree is symmetric
        if(!root) return true;
        // Check if left and right subtrees are mirror images
        return mirror(root->left, root->right);
    }
};
