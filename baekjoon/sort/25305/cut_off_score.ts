let lines : string[] = require('fs').readFileSync(0).toString().trim().split('\n');
let first_input : number[] = lines[0].split(' ').map(Number);
let scores : number[] = lines[1].split(' ').map(Number);

scores.sort((a, b) => b - a);

console.log(scores[first_input[1] - 1]);
