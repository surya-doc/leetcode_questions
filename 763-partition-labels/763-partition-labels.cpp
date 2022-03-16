class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>mp;
        int n = s.size();
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }
        vector<int>ans;
        for(int i=0; i<n;){
            int a = mp[s[i]];
            int max_1 = a;
            int prev = i;
            for(int j=i; j<=a; j++){
                if(mp[s[j]] > max_1){
                    max_1 = mp[s[j]];
                    a = max_1;
                }
            }
            ans.push_back(max_1-prev+1);
            prev = max_1;
            i = max_1+1;
        }
        return ans;
    }
};