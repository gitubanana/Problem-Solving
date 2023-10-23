const n = Number(require('fs').readFileSync(0).toString());
const dp : bigint[] = [];

dp[0] = BigInt(0);
dp[1] = BigInt(1);
for (var i = 2; i <= n; ++i)
    dp[i] = dp[i - 1] + dp[i - 2];

console.log(dp[n].toString());
