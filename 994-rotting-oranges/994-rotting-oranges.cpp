class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int one = 0;
        int two = 0;
        int zero = 0;
        int ans = 0;
        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid[0].size();
        int rotten = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0){
                    zero++;
                }
                else if(grid[i][j] == 1){
                    one++;
                }
                else if(grid[i][j] == 2){
                    two++;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int length = q.size();
            for(int a=0; a<length; a++){
                pair<int, int> temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                if(i-1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    rotten++;
                    q.push({i-1, j});
                }
                if(i+1 < row && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    rotten++;
                    q.push({i+1, j});
                }
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    rotten++;
                    q.push({i, j-1});
                }
                if(j+1 < col && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    rotten++;
                    q.push({i, j+1});
                }
            }
            ans++;
        }
        if(one > rotten){
            return -1;
        }
        if(ans == 0 || ans-1 == 0){
            return 0;
        }
        return ans-1;
    }
};