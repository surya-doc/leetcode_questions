class Solution {
public:
    int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
    {
        if(n>m){
            kthElement(arr2, arr1, m, n, k);
        }
        int l = max(0, k-m);
        int r = min(k, n);
        int ans;
        while(l <= r){
            int cut1 = (r+l)/2;
            int cut2 = k-cut1;
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            if(l1 <= r2 && l2 <= r1){
                return max(l1, l2);
            }
            else if(l1 > r2){
                r = cut1-1;
            }
            else{
                l = cut1+1;
            }
        }
        return 1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double ans;
        if((n+m)%2 != 0){
            ans = kthElement(nums1, nums2, n, m, (n+m)/2+1);
        }
        else{
            int temp = kthElement(nums1, nums2, n, m, (n+m)/2+1);
            cout << "*" << temp;
            ans = (kthElement(nums1, nums2, n, m, (n+m)/2+1) + kthElement(nums1, nums2, n, m, (n+m)/2))/2.0;
        }
        return ans;
    }
};