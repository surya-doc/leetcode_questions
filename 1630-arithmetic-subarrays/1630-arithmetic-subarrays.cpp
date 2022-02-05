class Solution {
public:
    bool checkForArithmatic(int left, int right, vector<int> &nums){
        vector<int>temp;
        for(int i=left; i<=right; i++){
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        int prev = temp[1]-temp[0];
        for(int i=1; i<temp.size()-1; i++){
            if(temp[i+1]-temp[i] != prev) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0; i<l.size(); i++){
            bool ans_bloc = checkForArithmatic(l[i], r[i], nums);
            ans.push_back(ans_bloc);
        }
        return ans;
    }
};