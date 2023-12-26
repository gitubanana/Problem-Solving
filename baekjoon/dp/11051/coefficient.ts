const DIVISOR = 10007;
const [N, R] = require('fs').readFileSync(0).toString().split(' ').map(Number);
var dp: Array<Array<number>> = new Array(N + 1);

dp[0] = new Array<number>(R + 1).fill(0);
for (let n = 1; n <= N; ++n)
{
    dp[n] = new Array<number>(R + 1).fill(1);
    for (let r = 1; r <= R; ++r)
    {
        if (n == r)
            continue ;

        dp[n][r] = ((dp[n - 1][r - 1] % DIVISOR)
                    + (dp[n - 1][r] % DIVISOR)) % DIVISOR;
    }
}

console.log(dp[N][R]);
