class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();                  // number of houses
        if(n == 0) return 0;
        int k = costs[0].size();               // number of colors
        vector<int> prev = costs[0];           // base case: first house
        for(int i = 1; i < n; i++) {
            // Step 1: find smallest and second smallest in prev
            int min1 = INT_MAX, min2 = INT_MAX;
            int min1Index = -1;
            for(int j = 0; j < k; j++) {
                if(prev[j] < min1) {
                    min2 = min1;               // update second min
                    min1 = prev[j];            // update first min
                    min1Index = j;             // store index of min1
                }
                else if(prev[j] < min2) {
                    min2 = prev[j];            // update second min
                }
            }
            vector<int> curr(k);
            // Step 2: compute current row
            for(int j = 0; j < k; j++) {
                // if same color as min1, we must use second min
                if(j == min1Index) {
                    curr[j] = costs[i][j] + min2;
                } 
                else {
                    curr[j] = costs[i][j] + min1;
                }
            }
            prev = curr;                       // move to next iteration
        }
        // Step 3: answer = min of last row
        return *min_element(prev.begin(), prev.end());
    }
};
