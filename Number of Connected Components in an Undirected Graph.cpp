class Solution {
private:
    void dfs(int i, vector<int>&vis, const vector<vector<int>>&adj) {
        vis[i] = 1;
        for(auto &next: adj[i]) {
            if(!vis[next]) {
                dfs(next, vis, adj);
            }
        }
        return;
    }    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n, 0);
        vector<vector<int>>adj(n);
        for(auto &edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                components++;
                dfs(i, vis, adj);
            }
        }
        return components;
    }
};
