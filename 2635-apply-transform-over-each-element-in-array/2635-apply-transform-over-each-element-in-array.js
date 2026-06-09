/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const newArr = [];
    arr.forEach((elem, idx) => {
        newArr[idx] = fn(elem, idx);
    });
    return newArr;
};