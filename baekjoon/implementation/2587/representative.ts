let str_arr : string[] = require('fs').readFileSync(0).toString().split('\n');
let num_arr : number[] = [];
let sum : number = 0;

function cmpSort(a, b) {
    return a - b;
}

for (let i : number = 0; i < 5; ++i) {
    num_arr.push(Number(str_arr[i]));
    sum += num_arr[i];
}

num_arr.sort(cmpSort);

console.log(sum / 5);
console.log(num_arr[2]);
