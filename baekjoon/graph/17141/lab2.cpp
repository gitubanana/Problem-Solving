#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

enum e_space
{
    EMPTY = 0,
    WALL,
    PUTTABLE
};

struct t_pos
{
    int y;
    int x;
};

const int MAX = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ans = INT_MAX;
int emptyCnt, mapSize, putCnt;
int map[MAX][MAX];
bool visited[MAX][MAX];
const int visitedSize = sizeof(visited);
std::vector<t_pos> virusPut;

void    bfs(std::queue<t_pos> &q)
{
    int time_ = 1;
    int removedEmptycnt = q.size();

    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_pos &cur = q.front();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (!(0 <= next.y && next.y < mapSize)
                    || !(0 <= next.x && next.x < mapSize)
                    || visited[next.y][next.x]
                    || map[next.y][next.x] == WALL)
                    continue;

                ++removedEmptycnt;
                if (removedEmptycnt == emptyCnt)
                {
                    ans = std::min(ans, time_);
                    return ;
                }
                visited[next.y][next.x] = true;
                q.push(next);
            }
            q.pop();
        }
        ++time_;
    }
}

void    findShortestTime(int start=0, int depth=0)
{
    static int toPut[10];
    static bool alreadyPut[10];

    if (depth == putCnt)
    {
        std::queue<t_pos> q;

        memset(visited, false, visitedSize);
        for (int i = 0; i < putCnt; ++i)
        {
            t_pos &virusPos = virusPut[toPut[i]];

            visited[virusPos.y][virusPos.x] = true;
            q.push(virusPos);
        }

        bfs(q);
        return ;
    }

    for (int i = start; i < virusPut.size(); ++i)
    {
        if (alreadyPut[i])
            continue ;

        alreadyPut[i] = true;
        toPut[depth] = i;
        findShortestTime(i + 1, depth + 1);
        alreadyPut[i] = false;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> mapSize >> putCnt;
    for (int y = 0; y < mapSize; ++y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            int &curSpace = map[y][x];

            std::cin >> curSpace;
            switch (curSpace)
            {
            case PUTTABLE:
                virusPut.push_back({y, x});
            case EMPTY:
                ++emptyCnt;
                break;
            }
        }
    }

    if (emptyCnt == virusPut.size() && emptyCnt == putCnt)
        ans = 0;
    else
        findShortestTime();
    std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
    return (0);
}
