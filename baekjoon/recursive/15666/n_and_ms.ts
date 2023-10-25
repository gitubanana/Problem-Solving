const [[_, comb_cnt], arr] = require('fs').readFileSync(0).toString().trim().split('\n').map((v) => v.split(' ').map(Number));

arr.sort((a, b) => (a - b));

function print_ans()
{
    const ans : string[] = [];
    const to_print : number[] = [];

    function back_tracking(cur_v : number, depth : number)
    {
        if (depth === comb_cnt)
        {
            ans.push(to_print.join(' '));
            return ;
        }

        for (var i = cur_v; i < arr.length; ++i)
        {
            if (i > 0 && arr[i] === arr[i - 1])
                continue ;

            to_print[depth] = arr[i];
            back_tracking(i, depth + 1);
        }
    }

    back_tracking(0, 0);
    console.log(ans.join('\n'));
}

print_ans();
