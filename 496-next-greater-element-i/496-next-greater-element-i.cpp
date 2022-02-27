class Solution {
public:
    int getTheNextGreater(stack<int>temp, int num){
        int greater = -1;
        while(temp.top() != num){
            if(temp.top() > num) greater = temp.top();
            temp.pop();
        }
        return greater;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans(nums1.size());
        for(int i=0; i<nums2.size(); i++){
            st.push(nums2[i]);
        }
        for(int i=0; i<nums1.size(); i++){
            stack<int>temp = st;
            ans[i] = getTheNextGreater(temp, nums1[i]);
        }
        return ans;
    }
};