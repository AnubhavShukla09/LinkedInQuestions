class Solution {
public:
    int longestOnesCircular(vector<int>& nums, int k) {
        int n = nums.size();
        // Create extended array
        vector<int> extended(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            extended[i] = nums[i % n];
        }
        int left = 0, zeros = 0, ans = 0;
        for (int right = 0; right < 2 * n; right++) {
            if (extended[right] == 0) zeros++;   // Count zeros in window
            // Shrink window if:
            // 1. zeros exceed k
            // 2. window size > n (IMPORTANT for circular constraint)
            while (zeros > k || (right - left + 1) > n) {
                if (extended[left] == 0) zeros--;
                left++;
            }
            ans = max(ans, right - left + 1);   // Update max window
        }

        return ans;
    }
};
