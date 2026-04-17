#include <iostream>

const int       MAX = 501;
const int       FRIEND = 1;

int     matrix[MAX][MAX];
int     visited[MAX];
int     ans;

void    dfs(int cur_v, int &man_cnt, int depth)
{
        if (depth != 1 && (visited[cur_v] == 1 || depth > 2))
                return ;
        ans += (visited[cur_v] == 0);;
        visited[cur_v] = 1;
        for (int i = 2; i <= man_cnt; i++)
                if (matrix[cur_v][i] == FRIEND)
                        dfs(i, man_cnt, depth + 1);
}

int     main(void)
{
        int     a, b;
        int     man_cnt, list_cnt;

        std::cin >> man_cnt >> list_cnt;
        while (list_cnt--)
        {
                std::cin >> a >> b;
                matrix[a][b] = FRIEND;
                matrix[b][a] = FRIEND;
        }
        dfs(1, man_cnt, 0);
        std::cout << ans - 1;
        return (0);
}