let lines = require('fs').readFileSync(0).toString().trim().split('\n');
let comb_cnt = lines[0].split(' ').map(Number)[1];
let arr = lines[1].split(' ').map(Number);
let visited = [];
let to_print = [];
let ans = [];

arr.sort((a, b) => (a - b));

back_tracking(0);

var _set = new Set<string>(ans);
var iter = _set.values();
for (var i = 0; i < _set.size; ++i)
    console.log(iter.next().value);

function back_tracking(depth)
{
    var i;

    if (comb_cnt == depth)
    {
        ans.push(to_print.join(' '));
        return ;
    }

    for (i = 0; i < arr.length; ++i)
    {
        var cur = arr[i];

        if (visited[i] === 1)
            continue ;

        visited[i] = 1;
        to_print[depth] = cur;
        back_tracking(depth + 1);
        visited[i] = 0;
    }
}