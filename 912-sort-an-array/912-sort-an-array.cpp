class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>minheap;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            minheap.push(nums[i]);
        }
        while(minheap.size() > 0){
            ans.push_back(minheap.top());
            minheap.pop();
        }
        return ans;
    }
};