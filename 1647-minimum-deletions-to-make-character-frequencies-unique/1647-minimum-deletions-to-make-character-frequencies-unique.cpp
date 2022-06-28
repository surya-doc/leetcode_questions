class Solution {
public:
    int minDeletions(string s) {
        int arr[26] = {0};
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<s.size(); i++){
            arr[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(arr[i] > 0){
                if(mp[arr[i]]){
                    cout << arr[i];
                    int j=0;
                    for(; j<=arr[i]; j++){
                        if(!mp[arr[i]-j] || arr[i]-j == 0){
                            break;
                        }
                    }
                    ans += j;
                    mp[arr[i]-j]++;
                }
                else{
                    mp[arr[i]]++;
                }  
            }
        }
        
        return ans;
    }
};