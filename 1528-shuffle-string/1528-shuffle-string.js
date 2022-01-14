/**
 * @param {string} s
 * @param {number[]} indices
 * @return {string}
 */
var restoreString = function(s, indices) {
    var arr = new Array(s.length);
    var i = 0;
    indices.map((index) => {
        arr[index] = s[i];
        i++;
    })
    
    var ans = arr.join('');
    return ans;
};