class Solution {
public:
    bool foundP, foundQ;              // flags to track existence
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        foundP = false;
        foundQ = false;
        TreeNode* ans = solve(root, p, q);             // compute LCA
        return (foundP && foundQ) ? ans : nullptr;     // ensure both exist
    }

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;            // base case
        
        TreeNode *l = solve(root->left, p, q);         // search left
        TreeNode *r = solve(root->right, p, q);        // search right
        
        if(root == p) { foundP = true; return root; }  // found p
        if(root == q) { foundQ = true; return root; }  // found q
        
        if(!l && r) return r;                          // only right found
        if(l && !r) return l;                          // only left found
        if(l && r) return root;                        // both sides → LCA
        
        return nullptr;                                // nothing found
    }
};
// TC - O(n)
// SC - O(h)
