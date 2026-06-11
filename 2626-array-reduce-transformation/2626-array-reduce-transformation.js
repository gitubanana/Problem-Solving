/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var result = init;

    for (num of nums) {
        result = fn(result, num);
    }
    return result;
};