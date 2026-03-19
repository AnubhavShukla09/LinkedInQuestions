class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int num: nums) {
            pq.push(num);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};
// O(n log k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();                              // total number of elements
        return quickSelect(nums, 0, n - 1, n - k);        // convert kth largest → (n-k)th smallest
    }
private:
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right];                          // choose last element as pivot
        int p = left;                                     // pointer for smaller elements

        for (int i = left; i < right; i++) {              // iterate through current range
            if (nums[i] <= pivot) {                       // if element <= pivot
                swap(nums[i], nums[p]);                   // move it to correct partition
                p++;                                      // expand smaller elements region
            }
        }
        swap(nums[p], nums[right]);                       // place pivot at its correct position
        if (p == k) return nums[p];                       // found the kth smallest element
        else if (p < k)                                  // kth element lies on right side
            return quickSelect(nums, p + 1, right, k);    // recurse on right partition
        else                                              // kth element lies on left side
            return quickSelect(nums, left, p - 1, k);     // recurse on left partition
    }
};
//O(n) avg
//O(1)
