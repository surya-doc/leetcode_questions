/**
 * @param {number} n
 * @param {number} k
 * @return {character}
 */
var getBit = function(i, s, target){
    if(i > target) return s;
    var temp = "";
    for(var j=0; j<s.length; j++){
        temp += s[j] === '0' ? '1' : '0';
    }
    s += ('1');
    s += temp.split('').reverse().join('');
    return getBit(i+1, s, target);
}

var findKthBit = function(n, k) {
    var s = "0";
    s = getBit(2, s, n);
    return s[k-1];
};