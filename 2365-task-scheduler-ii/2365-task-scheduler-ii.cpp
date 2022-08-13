class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0;
        unordered_map<int, long long> mp;
        for(auto it:tasks){
            if(mp[it]){
                if(day < mp[it]){
                    day = mp[it];
                }
                mp[it] = day+space+1;
                day++;
            }
            else{
                mp[it] = day+space+1;
                day++;
            }
        }
        return day;
    }
};