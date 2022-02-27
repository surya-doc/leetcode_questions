/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var maximumScore = function(a, b, c) {
    var total = a+b+c;
    var max_ele = Math.max(a, b, c);
    console.log(max_ele);
    // console.log(arr[0], arr[1], arr[2]);
    if((total-max_ele) <= max_ele){
        return (total-max_ele);  
    }
    else{
        // console.log
        return (parseInt((a+b+c)/2));
    }
};