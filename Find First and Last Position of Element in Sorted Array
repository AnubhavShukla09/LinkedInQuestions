class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(begin(nums), end(nums), target) - begin(nums);
        int r = lower_bound(begin(nums), end(nums), target+1) - begin(nums) - 1;
        if(l>=0 and l<nums.size() and nums[l]==target) return {l, r};
        return {-1, -1};
    }
};
