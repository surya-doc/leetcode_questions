class Solution {
public:
    
    int getPath(vector<vector<int>> &grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i == m){
            return j;
        }
        if(grid[i][j] == 1){
            if(j != n-1 && grid[i][j] == grid[i][j+1]){
                return getPath(grid, i+1, j+1);
            }
            else{
                return -1;
            }
        }
        if(grid[i][j] == -1){
            if(j != 0 && grid[i][j] == grid[i][j-1]){
                return getPath(grid, i+1, j-1);
            }
            else{
                return -1;
            }
        }
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = getPath(grid, 0, i);
        }
        return ans;
    }
};