class Solution {
public:
    vector<vector<int>>dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void bfs(int a, int b, vector<vector<char>>& grid, const int rows, const int cols) {
        queue<pair<int, int>> q;
        q.push({a, b});
        grid[a][b] = '0';
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (auto& dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x < 0 or y < 0 or x == rows or y == cols or grid[x][y]=='0')
                    continue;
                grid[x][y] = '0';
                q.push({x, y});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), islands = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j]=='1') {
                    islands++;
                    bfs(i,j,grid,rows,cols);
                }
            }
        }
        return islands;
    }
};
