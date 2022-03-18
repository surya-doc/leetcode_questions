class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int ans = 0;
//         for(int i=0; i<nums.size(); i++){
//             mp[nums[i]]++;
//         }
//         for(auto it:mp){
//             if(it.first < k){
//                 if(k-it.first == (k/2) && k%2 == 0){
//                     ans += (it.second)/2;
//                 }
//                 else{
//                     if(mp[k-it.first] >= 1){
//                         int l_temp = it.second;
//                         int r_temp = mp[k-it.first];
//                         int add = min(l_temp, r_temp);
//                         ans += add;
//                         mp[it.first] -= add;
//                         mp[k-it.first] -= add;
//                     }
//                 }
//             }

//         }
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[j]+nums[i] == k){
                ans++;
                j--;
                i++;
            }
            else{
                if(nums[i]+nums[j] > k){
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};