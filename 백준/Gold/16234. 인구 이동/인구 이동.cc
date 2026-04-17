#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int L, R;
int sum;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
std::vector<t_pos> toChange;
std::queue<t_pos> toCheck;

void    dfs(const t_pos &cur)
{
    const int &curSpace = map[cur.y][cur.x];

    toChange.push_back(cur);
    sum += curSpace;
    visited[cur.y][cur.x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            cur.y + dy[dir],
            cur.x + dx[dir]
        };

        if (!(0 <= next.y && next.y < size)
            || !(0 <= next.x && next.x < size)
            || visited[next.y][next.x])
            continue ;

        const int &nextSpacce = map[next.y][next.x];
        int diff = std::abs(curSpace - nextSpacce);

        if (!(L <= diff && diff <= R))
            continue ;

        dfs(next);
    }
}

void simulation(void)
{
    int qSize = toCheck.size();

    memset(visited, false, sizeof(visited));
    while (qSize--)
    {
        t_pos cur = toCheck.front();
        toCheck.pop();

        if (visited[cur.y][cur.x])
            continue ;

        sum = 0;
        toChange.clear();
        dfs(cur);
        if (toChange.size() > 1)
        {
            int avg = sum / toChange.size();

            for (const t_pos &pos : toChange)
            {
                toCheck.push(pos);
                map[pos.y][pos.x] = avg;
            }
        }
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> L >> R;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
            toCheck.push({y, x});
        }
    }

    int ans = -1;
    do
    {
        ++ans;
        simulation();
    } while (!toCheck.empty());

    std::cout << ans << '\n';
    return 0;
}
