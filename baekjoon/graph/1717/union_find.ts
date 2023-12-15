const lines = require('fs').readFileSync(0).toString().trim().split('\n');
const [vCnt, cmdCnt] = lines[0].split(' ').map(Number);

function print_ans()
{
    const parents : number[] = Array(vCnt + 1).fill(0);
    
    for (var i = 1; i <= vCnt; ++i)
        parents[i] = i;

    function getParent(x: number)
    {
        if (parents[x] == x)
            return x;
        return parents[x] = getParent(parents[x]);
    }

    function union(x: number, y: number)
    {
        const xParent = getParent(x);
        const yParent = getParent(y);

        if (xParent > yParent)
            parents[xParent] = yParent;
        else
            parents[yParent] = xParent;
    }

    var cmd, x, y;
    for (var i = 1; i < lines.length; ++i)
    {
        [cmd, x, y] = lines[i].split(' ').map(Number);
        if (cmd == 0)
            union(x, y);
        else
            console.log(getParent(x) == getParent(y) ? "YES" : "NO");
    }
}

print_ans();
