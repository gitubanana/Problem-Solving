/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    var cur = 0, next = 1, prev;

    while (true) {
        yield cur;
        prev = cur;
        cur = next;
        next = prev + cur;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */