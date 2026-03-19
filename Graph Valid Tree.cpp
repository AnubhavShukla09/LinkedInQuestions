class Solution {
public:
    vector<int> parent, rank;                         // parent[i] = parent of node i, rank = tree depth heuristic
    // Find the ultimate parent (root) of node x with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);              // compress path to make future queries faster
        return parent[x];                             // return root
    }
    // Union two nodes x and y
    bool unite(int x, int y) {
        int px = find(x);                             // find root of x
        int py = find(y);                             // find root of y
        // If both nodes have same root → adding this edge creates a cycle
        if (px == py) return false;
        // Union by rank: attach smaller tree under larger tree
        if (rank[px] > rank[py])
            parent[py] = px;                          // attach py under px
        else if (rank[px] < rank[py])
            parent[px] = py;                          // attach px under py
        else {
            parent[py] = px;                          // attach py under px (arbitrary)
            rank[px]++;                               // increase rank since height increases
        }
        return true;                                  // union successful (no cycle)
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // A valid tree must have exactly n-1 edges
        if (edges.size() != n - 1) return false;
        parent.resize(n);                             // initialize parent array
        rank.resize(n, 0);                            // initialize rank array with 0
        // Initially, each node is its own parent (disjoint sets)
        for (int i = 0; i < n; i++)
            parent[i] = i;
        // Process each edge
        for (auto& e : edges) {
            if (!unite(e[0], e[1]))
                return false;                         // cycle detected → not a tree
        }
        // If no cycles and edges = n-1 → graph must be connected
        return true;
    }
};
// TC - O(n + edges.size() * α(n))
// SC - O(n)
