// 1, 3, 5, 11, 21, 43, 85, 171
let n : number = Number(require('fs').readFileSync(0).toString().trim());
let dp : number[] = [];

dp.push(1);
dp.push(3);
for (let i = 2; i < n; ++i)
{
    dp.push((dp[i - 2] * 2 + dp[i - 1]) % 10007);
}

console.log(dp[n - 1] % 10007);
