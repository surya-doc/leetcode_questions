class Solution {
public:
    
    bool getTheAns(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &dp1, vector<vector<int>> &dp2){
        // cout << i << " " << j << " " << k << "\n";
        if(k >= 0 && i < 0 && j < 0){
            return false;
        }
        if(k < 0 && (i >= 0 || j >= 0)){
            return false;
        }
        if(k < 0){
            return true;
        }
        int ans1 = false;
        int ans2 = false;
        int flag = 0;
        if(i >= 0 && k >= 0 && dp1[i][k] != -1){
            ans1 = dp1[i][k];
            flag++;
        }
        if(j >= 0 && k >= 0 && dp2[j][k] != -1){
            ans2 = dp2[j][k];
            flag++;
        }
        if(flag >= 2){
            return ans1 | ans2;
        }
        if(i >= 0 && k >= 0 && s3[k] == s1[i]){
            ans1 = dp1[i][k] = getTheAns(s1, s2, s3, i-1, j, k-1, dp1, dp2);
        }
        if(j >= 0 && k >= 0 && s3[k] == s2[j]){
            ans2 = dp2[j][k] = getTheAns(s1, s2, s3, i, j-1, k-1, dp1, dp2);
        }
        return  ans1 | ans2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int l = s3.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (l+1, -1)));
        vector<vector<int>> dp1(n, vector<int> (l, -1));
        vector<vector<int>> dp2(m, vector<int> (l, -1));
        return getTheAns(s1, s2, s3, n-1, m-1, l-1, dp1, dp2);
        // return true;
    }
};