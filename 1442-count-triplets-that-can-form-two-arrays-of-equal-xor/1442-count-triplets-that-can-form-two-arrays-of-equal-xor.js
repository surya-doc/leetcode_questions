/**
 * @param {number[]} arr
 * @return {number}
 */
var countTriplets = function(arr) {
    var ans = 0;
    for(var i=0; i<arr.length; i++){
        var xor_a = arr[i];
        for(var j=i+1; j<arr.length; j++){
            xor_a ^= arr[j]
            if(xor_a === 0){
                ans += (j-i);
            }
        }
    }
    return ans;
};