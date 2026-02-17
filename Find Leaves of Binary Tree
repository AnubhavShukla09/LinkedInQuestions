class Solution {
private:
    vector<vector<int>>ans;
    int dfs(TreeNode* root) {
        if(!root) return -1;

        int lh = 1+dfs(root->left);
        int rh = 1+dfs(root->right);

        int h = max(lh, rh);

        if(h==ans.size()) {
            ans.push_back({});
        }
        ans[h].push_back(root->val);

        return h;
    }    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
