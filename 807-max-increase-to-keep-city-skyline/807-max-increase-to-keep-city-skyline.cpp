class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row_max[grid.size()];
        int col_max[grid[0].size()];
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            int temp = INT_MIN;
            for(int j=0; j<grid[0].size(); j++){
                temp = max(temp, grid[i][j]);
            }
            row_max[i] = temp;
        }
        for(int i=0; i<grid[0].size(); i++){
            int temp = INT_MIN;
            for(int j=0; j<grid.size(); j++){
                temp = max(temp, grid[j][i]);
            }
            col_max[i] = temp;
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                int min_1 = min(row_max[i], col_max[j]);
                ans += (min_1-grid[i][j]);
            }
        }
        return ans;
    }
};