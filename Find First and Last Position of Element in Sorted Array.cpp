class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(begin(nums), end(nums), target) - begin(nums);
        int r = lower_bound(begin(nums), end(nums), target+1) - begin(nums) - 1;
        if(l>=0 and l<nums.size() and nums[l]==target) return {l, r};
        return {-1, -1};
    }
};

class Solution {
public:

    // Find first occurrence of target
    int findFirst(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;                                      // store result
        
        while(l <= r) {
            int mid = l + (r - l) / 2;                     // avoid overflow
            
            if(nums[mid] == target) {
                ans = mid;                                // potential answer
                r = mid - 1;                              // move left to find earlier occurrence
            }
            else if(nums[mid] < target) {
                l = mid + 1;                              // go right
            }
            else {
                r = mid - 1;                              // go left
            }
        }
        
        return ans;                                       // first index or -1
    }

    // Find last occurrence of target
    int findLast(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;                                      // store result
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] == target) {
                ans = mid;                                // potential answer
                l = mid + 1;                              // move right to find later occurrence
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return ans;                                       // last index or -1
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);               // left boundary
        int last = findLast(nums, target);                 // right boundary
        
        return {first, last};                              // return result
    }
};
