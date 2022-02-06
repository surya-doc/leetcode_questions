class Solution {
public:
    static bool getOrder(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    int minSetSize(vector<int>& arr) {
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
            temp += it[1];
            ans++;
            if(temp >= arr.size()/2) break;
        }
        return ans;
    }
};