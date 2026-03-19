class Solution {
public:
    int longestOnesCircular(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, zeros = 0, ans = 0;
        for (int right = 0; right < 2 * n; right++) {
            if (nums[right % n] == 0) zeros++;  // simulate circular
            while (zeros > k || (right - left + 1) > n) {
                if (nums[left % n] == 0) zeros--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
