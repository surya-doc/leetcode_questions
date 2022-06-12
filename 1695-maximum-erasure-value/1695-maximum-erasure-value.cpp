class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int a=0;
        unordered_map<int, int> mp;
        int temp_sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(!mp[nums[i]]){
                mp[nums[i]]++;
                temp_sum += nums[i];
            }
            else{
                while(mp[nums[i]] != 0){
                    mp[nums[a]]--;
                    temp_sum -= nums[a];
                    a++;
                }
                // cout << i << "->" << temp_sum << " ";
                mp[nums[i]]++;
                temp_sum += nums[i];
            }
            ans = max(ans, temp_sum);
        }
        return ans;
    }
};