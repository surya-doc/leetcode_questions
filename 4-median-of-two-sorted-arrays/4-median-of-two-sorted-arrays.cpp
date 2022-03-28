class Solution {
public:
    int getTheNextEle(vector<int>& nums1, vector<int>& nums2, int p, int q){
        int l1 = nums1.size();
        int l2 = nums2.size();
        while(p<l1 && q<l2){
            if(nums1[p] <= nums2[q]){
                return nums1[p++];
            }
            else{
                return nums2[q++];
            }
        }
        if(p<l1){
            return nums1[p++];
        }
        return nums2[q++];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int mid1 = (l1+l2-1)/2;
        double ans = 0;
        int p = 0;
        int q = 0;
        int counter = -1;
        int temp;
        while(p<l1 && q<l2){
            if(nums1[p] <= nums2[q]){
                temp = nums1[p++];
                counter++;
            }
            else{
                temp = nums2[q++];
                counter++;
            }
            if(counter == mid1){
                ans += temp;
                if((l1+l2)%2 == 0){
                    if(p<l1 && q<l2){
                        ans += min(nums1[p], nums2[q]);
                    }
                    else if(p<l1){
                        ans += nums1[p];
                    }
                    else if(q<l2){
                        ans += nums2[q];
                    }
                }
                break;
            }
        }
        while(p<l1){
            temp = nums1[p++];
            counter++;
            if(counter == mid1){
                ans += temp;
                if((l1+l2)%2 == 0){
                    if(p<l1){
                        ans += nums1[p];
                    }
                    else if(q<l2){
                        ans += nums2[q];
                    }
                }
                break;
            }
        }
        
        while(q<l2){
            temp = nums2[q++];
            counter++;
            if(counter == mid1){
                ans += temp;
                if((l1+l2)%2 == 0){
                    if(p<l1){
                        ans += nums1[p];
                    }
                    else if(q<l2){
                        ans += nums2[q];
                    }
                }
                break;
            }
        }
        return (l1+l2)%2 == 0 ? ans/2 : ans;
    }
};