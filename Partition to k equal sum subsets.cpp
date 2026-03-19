class Solution {
public:
    bool solve(int start, int subsetSum, int k, int n, vector<int> &subsetSums, vector<int> &nums) {
        if(start == n) {                                   // all elements placed
            return true;                                   // valid partition found
        }
        for(int i = 0; i < k; i++) {                       // try placing nums[start] in each subset
            if(subsetSums[i] + nums[start] > subsetSum)    // exceed target sum
                continue;                                  // skip
            if(i > 0 && subsetSums[i] == subsetSums[i-1])  // avoid duplicate subset states
                continue;
            subsetSums[i] += nums[start];                  // choose: add element
            if(solve(start + 1, subsetSum, k, n, subsetSums, nums))
                return true;                               // solution found
            subsetSums[i] -= nums[start];                  // backtrack
            // PRUNING: if this subset was empty before placing nums[start]
            // and it didn't work, no need to try other empty subsets
            if(subsetSums[i] == 0) 
                break;
        }
        return false;                                      // no valid placement
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {   
        int n = nums.size();                               // number of elements
        int sum = 0;                                       // total sum
        for(int num : nums)
            sum += num;
        if(sum % k != 0)                                   // must be divisible
            return false;
        int subsetSum = sum / k;                           // target per subset
        sort(nums.begin(), nums.end(), greater<int>());    // sort descending (important pruning)
        if(nums[0] > subsetSum)                            // largest element check
            return false;
        vector<int> subsetSums(k, 0);                      // k buckets
        return solve(0, subsetSum, k, n, subsetSums, nums); // start recursion
    }
};

// TC - O(k^n)   // worst case backtracking
// SC - O(n + k) // recursion stack + subsetSums

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();                              // number of elements
        int sum = 0;                                      // total sum
        for(int num : nums)
            sum += num;                                   // compute total sum
        if(sum % k != 0)                                  // must be divisible
            return false;
        int target = sum / k;                             // target sum per subset
        sort(nums.begin(), nums.end(), greater<int>());   // sort descending (optimization)
        if(nums[0] > target)                              // largest element check
            return false;
        int totalMasks = (1 << n);                        // total possible subsets (2^n)
        vector<int> dp(totalMasks, -1);                   // dp[mask] = current subset sum mod target
        dp[0] = 0;                                        // base case: no elements used
        for(int mask = 0; mask < totalMasks; mask++) {    // iterate over all masks
            if(dp[mask] == -1) continue;                  // skip invalid states
            for(int i = 0; i < n; i++) {                  // try to pick each element
                if(mask & (1 << i)) continue;             // skip if already used
                int nextSum = dp[mask] + nums[i];         // new subset sum
                if(nextSum > target) continue;            // cannot exceed target
                int nextMask = mask | (1 << i);           // include element i
                dp[nextMask] = nextSum % target;          // reset to 0 if target reached
            }
        }
        return dp[totalMasks - 1] == 0;                   // all elements used & valid partition
    }
};
// TC - O(n * 2^n)
// SC - O(2^n)
