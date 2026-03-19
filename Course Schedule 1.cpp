class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>in(n, 0);
        unordered_map<int, vector<int>>adj;
        for(auto &p: pre) {
            int u = p[0], v = p[1];
            in[u]++;
            adj[v].push_back(u);
        }
        queue<int>q;
        int x = 0;
        for(int i = 0 ; i < n; i++) {
            if(!in[i]) {
                q.push(i);
                x++;
            }
        }
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto next: adj[curr]) {
                in[next]--;
                if(!in[next]) {
                    x++;
                    q.push(next);
                }
            }
        }
        return x==n;
    }
};
