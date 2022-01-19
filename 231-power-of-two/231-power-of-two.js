/**
 * @param {number} n
 * @return {boolean}
 */
function getAns(n){
    if(n === 0) return 0;
    if(n === 1) return 1;
    if(n%2 === 0) return getAns(n/2);
    else return 0;
}
var isPowerOfTwo = function(n) {
    var ans = false;
    ans = getAns(n);
    return ans;
};