class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=1, j=arr.size()-2;
        int mountain = 0;
        while(i <= j){
            int mid = i+(j-i)/2;
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
                mountain = mid;
                break;
            }
            else if(arr[mid+1] > arr[mid]){
                i = mid+1;
            }
            else if(arr[mid-1] > arr[mid]){
                j = mid-1;
            }
        }
        return mountain;
    }
};