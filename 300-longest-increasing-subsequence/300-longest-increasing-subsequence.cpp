class Solution {
public:
    //using binary search
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                auto indx = lower_bound(temp.begin(), temp.end(), nums[i]);
                temp[indx-temp.begin()] = nums[i];
            }
        }
        return temp.size();
    }
};