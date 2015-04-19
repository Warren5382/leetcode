class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>> &grid) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1') {
            grid[i][j] = '3';
            dfs(i-1, j , grid);
            dfs(i, j-1, grid);
            dfs(i+1, j, grid);
            dfs(i, j+1, grid);
            return true;
        }
        return false;
    }
    
    int numIslands(vector<vector<char>> &grid) {
        int num = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (dfs(i, j , grid)) {
                    num++;
                } 
            }
        }
        return num;
    }
};
