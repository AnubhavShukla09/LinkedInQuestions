class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();        // grid dimensions
        unordered_map<int, int> compSize;                     // map: component id -> size
        int cid = 2;                                          // start labeling from 2 (since grid has 0 and 1)
        vector<vector<int>> dirs = {{0,-1}, {-1,0}, {1,0}, {0,1}}; // 4 directions (left, up, down, right)
        queue<pair<int, int>> q;                              // BFS queue
        int ans = 1;                                          // at least 1 (if all 1s or single flip)
        // Step 1: label each island with unique component id and compute its size
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {                         // found unvisited land
                    q.push({i, j});                           // start BFS
                    grid[i][j] = cid;                         // mark with component id
                    int s = 1;                                // size of current component
                    while(!q.empty()) {
                        int a = q.front().first, b = q.front().second; // current cell
                        q.pop();
                        for(auto &dir : dirs) {               // explore neighbors
                            int x = a + dir[0], y = b + dir[1];
                            // skip out of bounds or non-land
                            if(x < 0 or y < 0 or x == rows or y == cols or grid[x][y] != 1) continue;
                            q.push({x, y});                  // push neighbor
                            grid[x][y] = cid;                // mark visited with component id
                            s++;                             // increment size
                        }
                    }
                    compSize[cid] = s;                       // store size of this component
                    ans = max(ans, s);                       // update max island size
                    cid++;                                   // move to next component id
                }
            }
        }
        // Step 2: try converting each 0 → 1 and compute merged island size
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {       
                if(grid[i][j] == 0) {                        // potential flip
                    unordered_set<int> comps;                // unique neighboring components
                    for(auto &dir : dirs) {                  // check neighbors
                        int x = i + dir[0], y = j + dir[1];
                        // skip invalid or water
                        if(x < 0 or y < 0 or x == rows or y == cols or grid[x][y] == 0) continue;
                        comps.insert(grid[x][y]);            // add component id
                    }
                    int curr = 1;                            // count this flipped cell
                    for(auto &c : comps) {                   // sum sizes of unique components
                        curr += compSize[c];
                    }
                    ans = max(ans, curr);                    // update answer
                }
            }
        }
        return ans;                                          // final maximum island size
    }
};
