class Solution {
public:
    bool check(vector<vector<int>> &h, int row, int col, int m, int n, int mid, int mark[100][100]){
        if(row == m-1 && col == n-1){
            return true;
        }
        mark[row][col] = 1;
        bool ret = false;
        if(row > 0 && mark[row-1][col] == 0 && abs(h[row][col]-h[row-1][col]) <= mid){
            ret = ret || check(h, row-1, col, m, n, mid, mark);
        }
        
        if(row < m-1 && mark[row+1][col] == 0 && abs(h[row][col]-h[row+1][col]) <= mid){
            ret = ret || check(h, row+1, col, m, n, mid, mark);
        }
        
        if(col > 0 && mark[row][col-1] == 0 && abs(h[row][col]-h[row][col-1]) <= mid){
            ret = ret || check(h, row, col-1, m, n, mid, mark);
        }
        
        if(col < n-1 && mark[row][col+1] == 0 && abs(h[row][col]-h[row][col+1]) <= mid){
            ret = ret || check(h, row, col+1, m, n, mid, mark);
        }
        return ret;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int mn = 0;
        int mx = 1e6;
        int m = heights.size();
        int n = heights[0].size();
        int ans = INT_MAX;
        int mid;
        while(mn < mx){
            mid = mn+(mx-mn)/2;
            int mark[100][100] = {0};
            if(check(heights, 0, 0, m, n, mid, mark)){
                ans = min(ans, mid);
                mx = mid;
            }
            else{
                mn = mid+1;
            }
        }
        return mn;
    }
};