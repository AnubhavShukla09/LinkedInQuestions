class Solution {
private:
    vector<int> heights, nsr, nsl;
    int n;
    void leftSmaller() {
        nsl.assign(n, -1);
        stack<int>st;
        st.push(0);
        for(int i = 1; i < n; i++) {
            while(!st.empty() and heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if(!st.empty())nsl[i] = st.top();
            st.push(i);
        }
    }
    void rightSmaller() {
        nsr.assign(n, n);
        stack<int>st;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--) {
            while(!st.empty() and heights[i]<=heights[st.top()]) {
                st.pop();
            }
            if(!st.empty())nsr[i] = st.top();
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        this->heights = heights;
        leftSmaller();
        rightSmaller();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int l = nsl[i]+1, r = nsr[i]-1;
            ans = max(ans, heights[i]*(r-l+1));
        }
        return ans;
    }
};
