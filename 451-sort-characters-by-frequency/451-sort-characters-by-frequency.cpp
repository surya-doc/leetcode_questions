class Solution {
public:
    static bool orderNumber(pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        vector<pair<char, int>>stor;
        int count = 0;
        int i = 0;
        for(; i<s.length()-1; i++){
            count++;
            if(s[i] != s[i+1]){
                stor.push_back({s[i], count});
                count = 0;
            }
        }
        if(s[i] != s[i-1]){
            stor.push_back({s[i], 1});
        }
        else{
            stor.push_back({s[i], count+1});
        }
        sort(stor.begin(), stor.end(), orderNumber);
        string a;
        for(auto it:stor){
            a += string(it.second, it.first);
        }
        return a;
    }
};