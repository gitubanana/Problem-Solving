/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    var cur = 0, next = 1;

    while (true) {
        yield cur;
        [cur, next] = [next, cur + next];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */