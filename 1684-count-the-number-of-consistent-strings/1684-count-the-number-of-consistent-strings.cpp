class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, int> mp;
        for(auto it:allowed){
            mp[it] = 1;
        }
        int ans = 0;
        for(auto it:words){
            int flag = 1;
            for(int i=0; i<it.length(); i++){
                if(!mp[it[i]]){
                    flag = 0;
                    break;
                }
            }
            ans += (flag == 1) ? 1 : 0;
        }
        return ans;
    }
};