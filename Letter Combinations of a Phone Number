class Solution {
private:
    vector<string> ans, mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n;
    string digits;
    void solve(int i, string curr) {
        if (i == n) {
            ans.push_back(curr);
            return;
        }
        string x = mp[digits[i] - '0'];
        for (char ch : x) {
            curr.push_back(ch);
            solve(i + 1, curr);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        n = digits.size();
        solve(0, "");
        return ans;
    }
};
