class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int>mp;
        sort(nums.begin(), nums.end());
        // int i=0, j=nums.size()-1;
        // while(i<j){
        //     if(nums[j]+nums[i] == k){
        //         ans++;
        //         j--;
        //         i++;
        //     }
        //     else{
        //         if(nums[i]+nums[j] > k){
        //             j--;
        //         }
        //         else{
        //             i++;
        //         }
        //     }
        // }
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(k-it.first == it.first){
                ans += (it.second)/2;
            }
            else if(mp.count(k-it.first)){
                int l_temp = it.second;
                int r_temp = mp[k-it.first];
                int add = min(l_temp, r_temp);
                ans += add;
                mp[it.first] -= add;
                mp[k-it.first] -= add;
            }
        }
        return ans;
    }
};