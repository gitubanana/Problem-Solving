/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    return this.reduce((groups, elem) => {
        const key = fn(elem);

        if (!Object.hasOwn(groups, key)) {
            groups[key] = [];
        }

        groups[key].push(elem);
        return groups;
    }, {});
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */