#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[i][j] = 1;
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && !vis[ni][nj]) {
                dfs(ni, nj, n, m, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int n = grid.size(), m = grid[0].size(), count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, n, m, vis, grid);
                    count++;
                }
            }
        }

        return count;
    }
};
