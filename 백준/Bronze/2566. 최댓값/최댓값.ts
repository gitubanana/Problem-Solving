const Y_SIZE = 9;
const X_SIZE = 9;
var arrays = require("fs").readFileSync(0).toString().split('\n');
var max : number = -1;
var ans : number[] = [];

for (var y = 0; y < Y_SIZE; ++y)
{
    var cur_array = arrays[y].toString().split(' ');
    for (var x = 0; x < X_SIZE; ++x)
    {
        var cur_value = Number(cur_array[x]);
        if (max < cur_value)
        {
            max = cur_value;
            ans = [y + 1, x + 1];
        }
    }
}

console.log(max);
console.log(ans[0] + " " + ans[1]);