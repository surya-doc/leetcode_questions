class Solution {
public:
    static bool orderNumber(pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        string ans = "";
        pair<char, int>stor[256] = {{0, 0}};
        // int count = 0;
        // int i = 0;
        // for(; i<s.length()-1; i++){
        //     count++;
        //     if(s[i] != s[i+1]){
        //         stor.push_back({s[i], count});
        //         count = 0;
        //     }
        // }
        // if(s[i] != s[i-1]){
        //     stor.push_back({s[i], 1});
        // }
        // else{
        //     stor.push_back({s[i], count+1});
        // }
        // sort(stor.begin(), stor.end(), orderNumber);
        // string a;
        // for(auto it:stor){
        //     a.append(it.second, it.first);
        // }
        // return a;
        for(auto it:s){
            stor[it].first = it;
            ++stor[it].second;
        }
        sort(begin(stor), end(stor), orderNumber);
        for(auto it:stor){
            ans.append(it.second, it.first);
        }
        return ans;
    }
};