/**
 * @param {string[]} sentences
 * @return {number}
 */
var mostWordsFound = function(sentences) {
    var len = 0;
    sentences.map((items) => {
        var temp = items.split(" ").length;
        len = len > temp ? len : temp;
    })
    return len;
};