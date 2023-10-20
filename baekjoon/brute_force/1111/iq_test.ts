let lines : string[] = require('fs').readFileSync(0).toString().trim().split('\n');
let arr : number[] = lines[1].split(' ').map(Number);
let a : number, b : number, divisor : number, i = 1;
let ans = {
    a : 0,
    b : 0,
    length : 0
};

function isPossible(arr : number[], a : number, b : number) : boolean
{
    for (let i = 1; i < arr.length; ++i)
    {
        if (arr[i - 1] * a + b !== arr[i])
        {
            return (false);
        }
    }
    return (true);
}

for (; i < arr.length - 1; ++i)
{
    divisor = arr[i] - arr[i - 1];
    if (divisor == 0)
        a = 0;
    else
        a = Math.floor((arr[i + 1] - arr[i]) / divisor);
    b = arr[i] - arr[i - 1] * a;
    if (isPossible(arr, a, b))
    {
        // a, b 넣기
        if (ans.length == 1
            && ans.a == a && ans.b == b)
            continue ;
        ans.a = a;
        ans.b = b;
        ++ans.length;
    }
}

if (arr.length == 1)
    console.log('A');
else if (arr.length == 2)
{
    if (arr[0] != arr[1])
        console.log('A');
    else
        console.log(arr[0]);
}
else if (ans.length == 1)
    console.log(arr[arr.length - 1] * ans.a + ans.b);
else if (ans.length > 1)
    console.log('A');
else
    console.log('B');
