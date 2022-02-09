class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // vector<int>ans;
        // int n = nums.size();
        // unordered_map<int, int> mp;
        // vector<int> arr[n+1];
        // for(int i=0; i<n; i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp){
        //     arr[it.second].push_back(it.first);
        // }
        // for(int i=n; i>=0; i--){
        //     if(arr[i].size() != 0){
        //         for(auto it:arr[i]){
        //             if(!k) break;
        //             ans.push_back(it);
        //             k--;
        //         }
        //     }
        //     if(!k) break;
        // }
        // return ans;
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>minheap;
        for(auto it:mp){
            minheap.push({it.second, it.first});
            if(minheap.size() > k){
                minheap.pop();
            }
        }
        while(minheap.size() > 0){
            ans.push_back(minheap.top()[1]);
            minheap.pop();
        }
        return ans;
    }
};