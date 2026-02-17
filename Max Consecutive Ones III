class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, r = 0;   // sliding window pointers
        int cnt = 0;        // number of zeros in current window
        int ans = 0;        // stores max window length

        // expand right pointer
        while (r < n) {

            // if we see a zero, we "flip" it (use one operation)
            if (nums[r] == 0) cnt++;

            // if zeros exceed k, shrink window from left
            while (cnt > k) {
                if (nums[l] == 0) cnt--; // release a flipped zero
                l++;
            }

            // update maximum valid window size
            ans = max(ans, r - l + 1);

            r++; // expand window
        }

        return ans;
    }
};
