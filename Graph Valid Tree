class Solution {
public:
    vector<int> parent, rank;
    // Find parent with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    // Union two nodes
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        // if same parent → cycle
        if (px == py) return false;
        // union by rank
        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // Tree must have exactly n-1 edges
        if (edges.size() != n - 1) return false;
        parent.resize(n);
        rank.resize(n, 0);
        // initially each node is its own parent
        for (int i = 0; i < n; i++)
            parent[i] = i;
        // process edges
        for (auto& e : edges) {
            if (!unite(e[0], e[1]))
                return false; // cycle detected
        }
        return true; // no cycles + n-1 edges ⇒ connected
    }
};
