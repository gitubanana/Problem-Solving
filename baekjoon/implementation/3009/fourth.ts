function find_cnt_1()
{
    for (let key in this)
        if (this[key] === 1)
            return key;
}

let lines : string[] = require('fs').readFileSync(0).toString().trim().split('\n');
let coordinates : number[][] = [];
let y_cnt = {};
let x_cnt = {};
let ans_y : string, ans_x : string;

for (let i = 0; i < lines.length; ++i)
{
    coordinates[i] = lines[i].split(' ').map(Number);
    let x = coordinates[i][0], y = coordinates[i][1];
    if (x_cnt[x] === undefined)
        x_cnt[x] = 0;
    if (y_cnt[y] === undefined)
        y_cnt[y] = 0;
    ++x_cnt[x];
    ++y_cnt[y];
}

console.log(find_cnt_1.apply(x_cnt), find_cnt_1.apply(y_cnt));
