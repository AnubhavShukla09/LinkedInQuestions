class Solution {
public:
    long ans = LONG_MAX; // store second minimum candidate
    int minVal;          // smallest value (root value)
    // DFS traversal
    void dfs(TreeNode* root) {
        if(!root) return; // base case
        // if value greater than minVal → possible answer
        if(root->val > minVal && root->val < ans) {
            ans = root->val;
        }
        // only continue if value equals minVal (optimization)
        // because children may contain second minimum
        if(root->val == minVal) {
            dfs(root->left);
            dfs(root->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        minVal = root->val; // smallest value
        dfs(root);
        // if no second minimum found
        return (ans == LONG_MAX) ? -1 : ans;
    }
};
