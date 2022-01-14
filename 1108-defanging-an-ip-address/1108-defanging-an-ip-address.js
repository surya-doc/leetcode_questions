/**
 * @param {string} address
 * @return {string}
 */
var defangIPaddr = function(address) {
    var a = address.replace(/\./g, "[.]");
    return a;
};