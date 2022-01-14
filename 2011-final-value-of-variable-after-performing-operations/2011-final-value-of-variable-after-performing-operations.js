/**
 * @param {string[]} operations
 * @return {number}
 */
var finalValueAfterOperations = function(operations) {
    var x=0;
    operations.map((item, index) => {
        switch(item){
            case "++X":
            case "X++":
                x++;
                break;
            case "--X":
            case "X--":
                x--;
                break;
        }
    })
    return x;
};