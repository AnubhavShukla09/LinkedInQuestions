class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size()) return false;      // lengths must match
        
        unordered_map<char, char> m1;               // map s → t
        unordered_map<char, char> m2;               // map t → s
        
        for(int i = 0; i < s.size(); i++) {
            
            char c1 = s[i], c2 = t[i];
            
            // If mapping exists, it must match
            if(m1.count(c1) && m1[c1] != c2) return false;
            
            // Reverse mapping must also match
            if(m2.count(c2) && m2[c2] != c1) return false;
            
            // Store mappings
            m1[c1] = c2;
            m2[c2] = c1;
        }
        
        return true;                                // valid isomorphic mapping
    }
};
