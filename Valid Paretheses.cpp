class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char &c: s) {
            if(c=='(' or c=='{' or c=='[') st.push(c);
            else if(st.empty()) return false;
            else {
                char t = st.top();
                st.pop();
                if(c==')' and t!='(') return false;
                if(c==']' and t!='[') return false;
                if(c=='}' and t!='{') return false;
            }
        }
        return st.empty();
    }
};
