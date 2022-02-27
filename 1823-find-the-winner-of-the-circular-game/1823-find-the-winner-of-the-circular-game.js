/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function(n, k) {
    var arr = [];
    for(var i=1; i<=n; i++){
        arr.push(i);
    }
    
    var res = k-1;
    while(arr.length > 1){
        arr.splice(res, 1);
        res = res+k-1;
        res = res%arr.length;
    }
    return arr[0];
};