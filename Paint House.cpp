class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();                    // number of houses
        
        if(n == 0) return 0;                     // edge case: no houses
        
        vector<int> prev = costs[0];             // base case: cost of painting first house
        
        for(int i = 1; i < n; i++) {             // iterate over remaining houses
            
            vector<int> curr(3);                 // current row (for house i)
            
            // If we paint current house with color 0,
            // previous house must be painted with color 1 or 2
            curr[0] = costs[i][0] + min(prev[1], prev[2]);
            
            // If we paint current house with color 1,
            // previous house must be painted with color 0 or 2
            curr[1] = costs[i][1] + min(prev[0], prev[2]);
            
            // If we paint current house with color 2,
            // previous house must be painted with color 0 or 1
            curr[2] = costs[i][2] + min(prev[0], prev[1]);
            
            prev = curr;                         // move current row to previous for next iteration
        }
        
        // answer is the minimum cost among all 3 colors for last house
        return min({prev[0], prev[1], prev[2]});
    }
};
