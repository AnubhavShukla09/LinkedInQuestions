class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        if(l1==0 and l2==0)return 0;
        if(l1==0)return l2;
        if(l2==0)return l1;
        vector<vector<int>>dp(l1+1, vector<int>(l2+1, INT_MAX));
        for(int i = 0; i < l1; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i < l2; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(word1[i-1]==word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[l1][l2];
    }
};
