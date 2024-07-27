#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>

enum e_space
{
    EMPTY = '.',
    WALL = 'X',
    START = 'S',
    EAT = 'K'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 1000;
const int MAX_EAT = 21;
const int WANT_EAT = 5 + 1;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, start, minDist = INT_MAX;
int dists[MAX_EAT][MAX_EAT];
char map[MAX_SIZE][MAX_SIZE + 1];
std::vector<t_pos> go;

void    bfs(int startIdx)
{
    static bool visited[MAX_SIZE][MAX_SIZE];

    int dist = 1;
    const t_pos &start = go[startIdx];
    std::queue<t_pos> q;

    memset(visited, false, sizeof(visited));
    visited[start.y][start.x] = true;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir],
                };

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == WALL
                    || visited[next.y][next.x])
                    continue ;

                char &nextSpace = map[next.y][next.x];
                if (startIdx < nextSpace && nextSpace < MAX_EAT)
                {
                    dists[startIdx][nextSpace] = dist;
                }

                visited[next.y][next.x] = true;
                q.push(next);
            }
        }

        ++dist;
    }
}

void    backTracking(int prev, int totalDist, int state)
{
    if (totalDist >= minDist)
        return ;

    if (__builtin_popcount(state) == WANT_EAT)
    {
        minDist = std::min(minDist, totalDist);
        return ;
    }

    for (int next = 0; next < go.size(); ++next)
    {
        int bit = (1 << next);
        int nextDist = dists[prev][next] + dists[next][prev];
        if (state & bit || nextDist == 0)
            continue ;

        backTracking(next, totalDist + nextDist, state | bit);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];

        for (int x = 0; x < xSize; ++x)
        {
            char &space = map[y][x];

            switch (space)
            {
            case START:
                start = go.size();
            case EAT:
                space = go.size();
                go.push_back({y, x});
                break ;
            }
        }
    }

    int goSize_1 = go.size() - 1;
    for (int i = 0; i < goSize_1; ++i)
    {
        bfs(i);
    }

    backTracking(start, 0, (1 << start));

    std::cout << (minDist == INT_MAX ? -1 : minDist) << '\n';
    return (0);
}
