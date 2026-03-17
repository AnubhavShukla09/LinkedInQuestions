class Solution {
private:
    int getMedian(const vector<int>&nums, const int &n) {
        if(n%2==1) {
            return nums[n/2];
        }
        return (nums[n/2] + nums[(n/2)-1])/2;
    }    
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int>x,y;
        int rows = grid.size(), cols = grid[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j]) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        sort(y.begin(), y.end());
        int ans = 0, n = x.size();
        int x1 = getMedian(x, n), y1 = getMedian(y, n);
        for(int i = 0; i < n; i++) {
            ans+=abs(x[i]-x1);
            ans+=abs(y[i]-y1);
        }
        return ans;
    }
};
