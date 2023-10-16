let [base, exp, c] = require('fs').readFileSync(0).toString().trim().split(' ').map(BigInt);
let save : bigint[] = [];

function multiply(base : bigint, exp : number) : bigint
{
    if (exp === 1)
        return (base % c);

    let half : number = Math.floor(exp / 2);
    let half2 : number = half + exp % 2;

    if (save[half] === undefined)
        save[half] = multiply(base, half);

    if (save[half2] === undefined)
        save[half2] = multiply(base, half2);

    return ((save[half] * save[half2]) % c);
}

console.log(multiply(base, Number(exp)).toString());
