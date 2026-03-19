class Solution {
public:
    
    // Backtracking function
    void dfs(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        
        // Base case: all positions fixed → one permutation ready
        if(idx == nums.size()) {
            ans.push_back(nums);                      // store current permutation
            return;
        }
        
        // Try placing each element at current index
        for(int i = idx; i < nums.size(); i++) {
            
            swap(nums[idx], nums[i]);                // fix nums[i] at position idx
            
            dfs(nums, idx + 1, ans);                 // recurse for next index
            
            swap(nums[idx], nums[i]);                // backtrack (restore original array)
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;                     // result container
        
        dfs(nums, 0, ans);                           // start recursion
        
        return ans;                                  // return all permutations
    }
};
// TC - O(n * n!)
// SC - O(n)    // recursion stack (excluding output)
