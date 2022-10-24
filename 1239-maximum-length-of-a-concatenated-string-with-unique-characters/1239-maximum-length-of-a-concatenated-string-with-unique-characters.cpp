class Solution {
public:
    
    int check(string s1, string s2){
        unordered_map<char, int> mp;
        for(int i=0; i<s1.size(); i++){
            mp[s1[i]]++;
        }
        for(int i=0; i<s2.size(); i++){
            if(mp[s2[i]]){
                return 0;
            }
            mp[s2[i]]++;
        }
        return 1;
    }
    
    int getMaxLength(string s, vector<string> &arr, int indx, map<char, int> &mp){
        if(indx >= arr.size()){
            return 0;
        }
        int not_take = 0+getMaxLength(s, arr, indx+1, mp);
        int take = 0;
        
        int match = check(s, arr[indx]);
        
        if(match){
            take = arr[indx].size()+getMaxLength(s+arr[indx], arr, indx+1, mp);
        }
        return max(not_take, take);
    }
    
    int maxLength(vector<string>& arr) {
        string s = "";
        map<char, int> mp;
        return getMaxLength(s, arr, 0, mp);
    }
};