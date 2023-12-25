const lines: string[] = require('fs').readFileSync(0).toString().split('\n');
const size: number = Number(lines[0]);
var dp: Array<Array<number>> = new Array(size);
var triangle: Array<Array<number>> = new Array(size);

for (let y = 0; y < size; ++y)
{
    dp[y] = new Array<number>(y + 1).fill(0);
    triangle[y] = lines[y + 1].split(' ').map(Number);
}

dp[0][0] = triangle[0][0];
for (let curY = 0; curY < size - 1; ++curY)
{
    let nextY = curY + 1;

    for (let curX = 0; curX <= curY; ++curX)
    {
        for (let i = 0; i <= 1; ++i)
        {
            let nextX = curX + i;

            dp[nextY][nextX] = Math.max(dp[nextY][nextX],
                dp[curY][curX] + triangle[nextY][nextX]
            );
        }
    }
}

console.log(Math.max(...dp[size - 1]));
