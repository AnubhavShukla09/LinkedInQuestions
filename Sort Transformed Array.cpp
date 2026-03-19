class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();                                   // Size of input array
        vector<int> result(n);                                 // Result array to store sorted transformed value
        int left = 0, right = n - 1;                           // Two pointers at both ends
        int index = (a >= 0) ? n - 1 : 0;                      // Fill from end if parabola opens up, else from start
        while (left <= right) {                                // Process all elements
            int leftVal = transform(nums[left], a, b, c);      // Transform left value
            int rightVal = transform(nums[right], a, b, c);    // Transform right value
            if (a >= 0) {                                      // Parabola opens upwards (U-shape)
                // Larger values are at the ends → fill from back
                if (leftVal >= rightVal) {
                    result[index--] = leftVal;                 // Place larger value at current index
                    left++;                                   // Move left pointer
                } else {
                    result[index--] = rightVal;                // Place larger value
                    right--;                                  // Move right pointer
                }
            } else {                                           // Parabola opens downwards (∩-shape)
                // Smaller values are at the ends → fill from front
                if (leftVal <= rightVal) {
                    result[index++] = leftVal;                 // Place smaller value at current index
                    left++;                                   // Move left pointer
                } else {
                    result[index++] = rightVal;                // Place smaller value
                    right--;                                  // Move right pointer
                }
            }
        }
        return result;                                         // Return sorted transformed array
    }
private:
    int transform(int x, int a, int b, int c) {
        return a * x * x + b * x + c;                          // Apply quadratic function
    }
};
// TC - O(n)
// SC - O(n)
