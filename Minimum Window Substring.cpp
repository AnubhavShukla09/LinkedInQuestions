class Solution {    
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq, window; // freq → required frequency of chars in t, window → current window frequency
        for (char ch : t) freq[ch]++; // build frequency map of t
        int l = 0, r = 0, n = s.size();
        int start = -1;        // starting index of best window
        int length = INT_MAX;  // minimum window length
        int required = freq.size(); // number of unique chars needed
        int formed = 0;             // how many chars currently satisfied
        while (r < n) {
            char curr = s[r];
            window[curr]++;   // include current char in window
            // check if current char satisfies required frequency
            if (freq.count(curr) && window[curr] == freq[curr]) {
                formed++;
            }
            // try shrinking window if all requirements satisfied
            while (l <= r && required == formed) {
                // update minimum window
                if (length > r - l + 1) {
                    start = l;
                    length = r - l + 1;
                }
                // remove leftmost char from window
                char last = s[l];
                window[last]--;
                // if requirement breaks, reduce formed
                if (freq.count(last) && window[last] < freq[last]) {
                    formed--;
                }
                l++; // shrink window
            }
            r++; // expand window
        }
        return start == -1 ? "" : s.substr(start, length);
    }
};
