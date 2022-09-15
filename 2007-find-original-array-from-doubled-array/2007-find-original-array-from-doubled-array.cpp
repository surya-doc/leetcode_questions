class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> mp;
        vector<int> ans;
        for(int i=0; i<changed.size(); i++){
            mp[changed[i]]++;
        }
        sort(changed.begin(), changed.end());
        for(int i=0; i<changed.size(); i++){
            // cout << it.first << "->" << it.second << " ";
            int val = changed[i];
            if(mp[val] > 0){
                mp[val]--;
                if(mp[val*2] > 0){
                    mp[val*2]--;
                    ans.push_back(val);
                }
                
                else{
                    return {};
                }
            }
        }
        return ans;
    }
};