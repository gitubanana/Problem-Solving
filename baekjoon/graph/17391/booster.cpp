#include <iostream>
#include <queue>

struct t_pos
{
    int y, x;
};

const int   MAX = 300;

int y_size, x_size;
int map[MAX][MAX];
int cnt[MAX][MAX];

int bfs(const t_pos &start, const t_pos &end)
{
    std::queue<t_pos>   q;

    q.push(start);
    cnt[start.y][start.x] = 1;
    while (!q.empty())
    {
        const t_pos &cur = q.front();
        const int   &item_cnt = map[cur.y][cur.x];

        for (int move = 1; move <= item_cnt; ++move)
        {
            const t_pos next_arr[] = {{cur.y, cur.x + move}, {cur.y + move, cur.x}};
            for (int i = 0; i < 2; ++i)
            {
                const t_pos &next = next_arr[i];

                if (!(0 <= next.y && next.y < y_size)
                    || !(0 <= next.x && next.x < x_size)
                    || cnt[next.y][next.x] != 0)
                    continue ;

                cnt[next.y][next.x] = cnt[cur.y][cur.x] + 1;
                if (next.y == end.y && next.x == end.x)
                    return (cnt[end.y][end.x] - 1);

                q.push(next);
            }
        }
        q.pop();
    }
    return (cnt[end.y][end.x]);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> y_size >> x_size;
    for (int y = 0; y < y_size; ++y)
        for (int x = 0; x < x_size; ++x)
            std::cin >> map[y][x];
    std::cout << bfs({0, 0}, {y_size - 1, x_size - 1}) << '\n';
    return (0);
}
