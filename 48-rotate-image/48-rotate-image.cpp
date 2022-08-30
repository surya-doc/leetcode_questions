class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            for(int i=0; i<(r-l); i++){
                int t = l;
                int b = r;
                int topLeft = matrix[t][l+i];
                int topRight = matrix[t+i][r];
                int bottomLeft = matrix[b-i][l];
                int bottomRight = matrix[b][r-i];
                matrix[t+i][r] = topLeft;
                matrix[b][r-i] = topRight;
                matrix[b-i][l] = bottomRight;
                matrix[t][l+i] = bottomLeft;
            }
            l++;
            r--;
        }
    }
};