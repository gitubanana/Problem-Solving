let arr : number[] = require('fs').readFileSync(0).toString().trim().split(' ').map(Number);
console.log(Math.abs((arr[0] + arr[3]) - (arr[1] + arr[2])));
