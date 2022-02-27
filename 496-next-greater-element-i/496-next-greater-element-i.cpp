class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        map<int, int>mp;
        for(int i=0; i<nums1.size(); i++){
            mp[nums1[i]] = -1;
        }
        vector<int>ans(nums1.size());
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && (st.top() <= nums2[i])){
                st.pop();
            }
            cout << nums2[i];
            if(mp[nums2[i]]){
                mp[nums2[i]] = st.empty() ? -1 : st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0; i<nums1.size(); i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};