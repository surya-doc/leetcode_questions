/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function sendPos(nums, target, di, n){
    var l = 0;
    var r = n-1;
    var returnable = -1;
    while(l <= r){
        var mid = l+(r-l)//2;
        if(nums[mid] === target){
            if(di){
                returnable = mid;
                r = mid-1;
            }
            else{
                returnable = mid;
                l = mid+1;
            }
        }
        else if(nums[mid] >  target){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return returnable;
}
var searchRange = function(nums, target) {
    var start = sendPos(nums, target, true, nums.length);
    var end = sendPos(nums, target, false, nums.length);
    var ans = [start, end];
    return ans;
};