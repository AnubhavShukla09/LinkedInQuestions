class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> vis, pos;              // vis → seen sequences, pos → repeated sequences
        int n = s.size();                            // length of string
        if(n <= 10) return {};                       // no possible repeated substring of length 10
        int r = 10;                                  // right pointer (end of window)
        string curr = s.substr(0, 10);               // first window of size 10
        vis.insert(curr);                            // mark first sequence as seen
        // Slide window across string
        while(r < n) {
            char ch = s[r];                          // next character to include
            curr.push_back(ch);                      // add new character at end
            curr.erase(curr.begin());                // remove first character → maintain size 10
            // If already seen → it's a repeated sequence
            if(vis.count(curr)) 
                pos.insert(curr);                    // store in result set (avoid duplicates)
            else 
                vis.insert(curr);                    // mark as seen
            r++;                                     // move window forward
        }
        vector<string> ans;                          // final result
        for(auto it : pos) {                         // convert set to vector
            ans.push_back(it);
        }
        return ans;                                  // return repeated sequences
    }
};
//O(n) both
