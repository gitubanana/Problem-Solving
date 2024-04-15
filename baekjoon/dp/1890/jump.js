function plusDp(nextY, nextX, curY, curX)
{
    if (!(0 <= nextY && nextY < mapSize)
        || !(0 <= nextX && nextX < mapSize))
        return ;

    dp[nextY][nextX] += dp[curY][curX];
}

const lines = require('fs').readFileSync(0).toString().split('\n');
const mapSize = Number(lines[0]);
const map_ = [];
const dp = Array(mapSize);
for (var i = 1; i <= mapSize; ++i)
{
    map_.push(lines[i].split(' ').map(Number));
    dp[i - 1] = new Array(mapSize).fill(BigInt(0));
}

dp[0][0] = BigInt(1);
for (var y = 0; y < mapSize; ++y)
{
    for (var x = 0; x < mapSize; ++x)
    {
        if (dp[y][x] == 0 || map_[y][x] == 0)
            continue ;

        plusDp(y + map_[y][x], x, y, x);
        plusDp(y, x + map_[y][x], y, x);
    }
}

console.log(dp[mapSize - 1][mapSize - 1].toString());
