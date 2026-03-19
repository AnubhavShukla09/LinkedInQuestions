class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string revS = s;
        reverse(revS.begin(), revS.end()); // reverse string
        int n = s.size();
        // dp[i][j] = LCS length of s[0..i-1] and revS[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // build LCS table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // if characters match → extend palindrome
                if(s[i - 1] == revS[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                // otherwise take best from left or top
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // final answer = LCS of full strings
        return dp[n][n];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string revS = s;                                      // copy original string
        reverse(revS.begin(), revS.end());                     // reverse i
        int n = s.size();                                     // length of string
        vector<int> prev(n + 1, 0), curr(n + 1, 0);            // only 2 rows needed
        for(int i = 1; i <= n; i++) {                         // iterate over original string
            for(int j = 1; j <= n; j++) {                     // iterate over reversed string
                if(s[i - 1] == revS[j - 1]) {                 // characters match
                    curr[j] = 1 + prev[j - 1];                // extend subsequence
                }
                else {
                    curr[j] = max(prev[j], curr[j - 1]);      // take max of top or left
                }
            }
            prev = curr;                                      // move current row to previous
        }
        return prev[n];                                       // final answer
    }
};
