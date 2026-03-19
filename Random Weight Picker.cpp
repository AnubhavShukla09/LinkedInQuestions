class Solution {
public:
    vector<int> prefix; // Stores cumulative weights
    int total = 0;      // Total sum of weights
    Solution(vector<int>& w) {
        for (int weight : w) {
            total += weight;          // Keep adding weights
            prefix.push_back(total);  // Build prefix sum
        }
    }
    int pickIndex() {
        int target = rand() % total + 1;  // Random number in [1, total]
        // Binary search: find first index where prefix[index] >= target
        int left = 0, right = prefix.size() - 1;
        int ans = right; // default (in case all prefix >= target)
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] >= target) {
                ans = mid;        // potential answer
                right = mid - 1;  // search left for first occurrence
            } else {
                left = mid + 1;   // go right
            }
        }
        return ans; // index with cumulative weight >= target
    }
};
// TC -
// Solution(w) : O(n)
// pickIndex() : O(log n)

// SC - O(n)
