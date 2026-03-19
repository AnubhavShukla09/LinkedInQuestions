class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>in(n, 0);
        unordered_map<int, vector<int>>adj;
        for(auto &p: pre) {
            int u = p[0], v = p[1];
            in[u]++;
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<int>x;
        for(int i = 0 ; i < n; i++) {
            if(!in[i]) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int curr = q.front();
            x.push_back(curr);
            q.pop();
            for(auto next: adj[curr]) {
                in[next]--;
                if(!in[next]) {
                    q.push(next);
                }
            }
        }
        if(x.size()!=n)return {};
        return x;
    }
};
// TC - O(n + pre.size())
// SC - O(n + pre.size())
