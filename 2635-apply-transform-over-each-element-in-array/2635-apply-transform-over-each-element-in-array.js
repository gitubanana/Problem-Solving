/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    return arr.reduce((newArr, elem, idx) => {
        newArr[idx] = fn(elem, idx);
        return newArr;
    }, []);
};