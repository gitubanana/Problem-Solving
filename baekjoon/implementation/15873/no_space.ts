const line: string = require('fs').readFileSync(0).toString();

var ans = 0;
if (line.substring(0, 1) == '10')
    ans = 10 + Number(line.substring(2));
else
    ans = line[0] - '0' + Number(line.substring(1));

console.log(ans);