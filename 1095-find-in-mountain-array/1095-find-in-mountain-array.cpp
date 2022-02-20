/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length()-1;
        int l = 0, r = n;
        int peakIndex = 0;
        while(l < r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid+1)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        peakIndex = l;
        l = 0, r = peakIndex-1;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        l = peakIndex, r = n;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return -1;
    }
};