let arr : number[] = require('fs').readFileSync(0).toString().trim().split(' ').map(Number);
let cnt : number;
let mid : number = (arr[0] + arr[1]) / 2;

if (arr[1] > arr[0])
    cnt = arr[1] - arr[0] + 1;
else
    cnt = arr[0] - arr[1] + 1;

console.log(mid * cnt);
