const lines = require('fs').readFileSync(0).toString().split('\n');
const N = BigInt(lines[0]);
var originSum = N * (N - BigInt(1)) / BigInt(2);

var num = '';
for (var i = 0; i < lines[1].length; ++i)
{
    if (lines[1][i] === ' ')
    {
        originSum -= BigInt(num);
        num = '';
    }
    else
        num += lines[1][i];
}

originSum -= BigInt(num);
console.log((-originSum).toString());
