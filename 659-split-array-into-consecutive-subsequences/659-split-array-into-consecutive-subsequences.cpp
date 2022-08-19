class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> list, sub;
        for(auto it:nums){
            list[it]++;
        }
        for(auto it:nums){
            if(list[it] == 0){
                continue;
            }
            list[it]--;
            if(sub[it-1] > 0){
                sub[it-1]--;
                sub[it]++;
            }
            else if(list[it+1] > 0 && list[it+2] > 0){
                list[it+1]--;
                list[it+2]--;
                sub[it+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};