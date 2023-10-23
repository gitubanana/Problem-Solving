const [[_, comb_cnt], arr] = require('fs').readFileSync(0).toString().trim().split('\n').map((v) => v.split(' ').map(Number));

arr.sort((a, b) => (a - b));

function print_ans()
{
    const visited : boolean[] = [];
    const ans : string[] = [];
    const to_print : number[] = [];

    function back_tracking(depth : number)
    {
        if (depth === comb_cnt)
        {
            ans.push(to_print.join(' '));
            return ;
        }

        for (var i = 0; i < arr.length; ++i)
        {
            if (visited[i])
                continue ;
            if ((i > 0 && arr[i] === arr[i - 1] && !visited[i - 1]))
                continue ;

            to_print[depth] = arr[i];
            visited[i] = true;
            back_tracking(depth + 1);
            visited[i] = false;
        }
    }

    back_tracking(0);
    console.log(ans.join('\n'));
}

print_ans();
