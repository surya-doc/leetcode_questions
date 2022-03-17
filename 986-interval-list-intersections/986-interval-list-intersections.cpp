class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        if(firstList.size() == 0 || secondList.size() == 0){
            return ans;
        }
        int i=0, j=0;
        int m = firstList.size();
        int n = secondList.size();
        
        while(i < m && j < n){
            if(firstList[i][1]>=secondList[j][0] && firstList[i][0]<=secondList[j][1]){
            vector<int>temp(2);
            temp[0] = max(firstList[i][0], secondList[j][0]);
            temp[1] = min(firstList[i][1], secondList[j][1]);
            ans.push_back(temp);

            }            
            if(secondList[j][1] >= firstList[i][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};