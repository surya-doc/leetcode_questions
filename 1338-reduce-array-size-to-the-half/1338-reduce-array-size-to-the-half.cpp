class Solution {
public:
    static bool getOrder(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    int minSetSize(vector<int>& arr) {
        // vector<int>stor;    
        // unordered_map<int, int> mp;
        // for(int i=0; i<arr.size(); i++){
        //     mp[arr[i]]++;
        // }
        // for(auto it:mp){
        //     stor.push_back(it.first);
        // }
        // sort(stor.begin(), stor.end());
        // int size = 0;
        // int i=0;
        // while(size >= (arr.size()/2)){
        //     size += mp[arr[i++]];
        // }
        // return i-1;
        int ans = 0;
        map<int, int>mp;
        vector<vector<int>> stor;
        int temp = 0;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            stor.push_back({it.first, it.second});
        }
        sort(stor.begin(), stor.end(), getOrder);
        for(auto it:stor){
            cout << it[0] <<"," << it[1] << "\n";
            temp += it[1];
            ans++;
            if(temp >= arr.size()/2) break;
        }
        return ans;
    }
};