class Solution {
public:
    
    int ans = 0;
    
    int islends(int i, int j, vector<vector<int>> &grid){
        if(grid[i][j] == 1){
            grid[i][j] = 0;
            int top = 0;
            if(i-1 >= 0 && i-1 < grid.size() && j >= 0 && j <= grid[0].size()){
                top = islends(i-1, j, grid);
            }
            int bottom = 0;
            if(i+1 >= 0 && i+1 < grid.size() && j >= 0 && j <= grid[0].size()){
                bottom = islends(i+1, j, grid);
            }
            int left = 0;
            if(i >= 0 && i <= grid.size() && j-1 >= 0 && j-1 < grid[0].size()){
                left = islends(i, j-1, grid);
            }
            int right = 0;
            if(i >= 0 && i <= grid.size() && j+1 >= 0 && j+1 < grid[0].size()){
                right = islends(i, j+1, grid);
            }
            return 1+top+bottom+left+right;
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    ans = max(ans, islends(i, j, grid));
                }
            }
        }
        return ans;
    }
};