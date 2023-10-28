var [v_cnt, leaf_cnt] = require('fs').readFileSync(0).toString().trim().split(' ').map(Number);
const root = 1;

console.log("0 1\n1 2");
for (var v = 3; v <= leaf_cnt; ++v)
{
    console.log(root, v);
}

var p = leaf_cnt;
for (v = leaf_cnt + 1; v < v_cnt; ++v)
{
    console.log(p, v);
    p = v;
}
