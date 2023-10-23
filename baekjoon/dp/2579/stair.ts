const arr : number[] = require('fs').readFileSync(0).toString().trim().split('\n').map(Number);
const dp : number[] = [];

arr.shift();

dp[0] = arr[0];
dp[1] = arr[0] + arr[1];
dp[2] = Math.max(arr[0], arr[1]) + arr[2];
for (var i = 3; i <= arr.length; ++i)
{
    dp[i] = Math.max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
}

console.log(dp[arr.length - 1]);
