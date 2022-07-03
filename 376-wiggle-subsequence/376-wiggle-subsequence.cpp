class Solution {
public:
    
    int getLen(vector<int> &temp, int indx, int flag, vector<int> &dp){
        if(indx >= temp.size()){
            return 0;
        }
        if(dp[flag+1] != -1){
            return dp[flag+1];
        }
        int take = 0;
        int not_take = 0+getLen(temp, indx+1, flag, dp);
        if(flag == -1 || (temp[indx] < 0 && temp[indx-1] > 0) || (temp[indx] > 0 && temp[indx-1] < 0)){
            take = 1+getLen(temp, indx+1, indx, dp);
        }
        return dp[flag+1] = max(take, not_take);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        if(n < 2){
            return n;
        }
        for(int i=1; i<n; i++){
            int dif = nums[i]-nums[i-1];
            if(dif != 0){
                temp.push_back(dif);
            }
        }
        vector<int> dp(n, -1);
        return 1+getLen(temp, 0, -1, dp);
    }
};