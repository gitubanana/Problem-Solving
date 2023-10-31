const root = 0;
var linked : number[][] = [];
var [first, ...lines] = require('fs').readFileSync(0).toString().trim().split('\n');
var v_cnt = Number(first);

for (var i = 0; i < v_cnt; ++i)
    linked.push([]);
for (var i = 0; i < lines.length; ++i)
{
    var [a, b] = lines[i].split(' ').map(Number);
    --a, --b;
    linked[a].push(b);
    linked[b].push(a);    
}

function print_ans() {
    var ans : number[] = Array(v_cnt);
    var visited : boolean[] = Array(v_cnt).fill(false);

    function dfs(cur : number) {

        visited[cur] = true;
        for (var i in linked[cur])
        {
            var child = linked[cur][i];

            if (visited[child] === true
                || linked[child].length === 0)
                continue ;

            ans[child] = cur + 1;
            dfs(child);
        }
    }

    dfs(root);
    ans.shift();
    console.log(ans.join('\n'));
}

print_ans();
