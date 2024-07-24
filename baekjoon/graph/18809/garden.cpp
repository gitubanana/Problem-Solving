#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>

enum e_space
{
    WATER = '0',
    EMPTY,
    CULTURING
};

struct t_pos
{
    int y, x;
};

template <typename T>
using t_vec = std::vector<T>;

const int MAX_SIZE = 50;
const int CULTURE_TYPE = 2;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int maxFlower;
int ySize, xSize, sowSum;
int cultureCnt[CULTURE_TYPE];
char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
t_vec<t_pos> sowable;
t_vec<int> landIdx[CULTURE_TYPE];

inline int getValue(int move, int type)
{
    return (move * (2 * type - 1));
}

int bfs(void)
{
    const static int NOT_VISITED = 0;
    const static int FLOWER = INT_MAX;

    int move = 1;
    std::queue<t_pos> qs[2];

    memset(visited, NOT_VISITED, sizeof(visited));
    for (int type = 0; type < CULTURE_TYPE; ++type)
    {
        std::queue<t_pos> &q = qs[type];

        for (const int &idx : landIdx[type])
        {
            t_pos &toPush = sowable[idx];

            visited[toPush.y][toPush.x] = getValue(move, type);
            q.push(toPush);
        }
    }

    int flowerCnt = 0;

    while (++move)
    {
        for (int type = 0; type < CULTURE_TYPE; ++type)
        {
            std::queue<t_pos> &q = qs[type];
            int qSize = q.size();

            if (qSize == 0)
                return (flowerCnt);

            while (qSize--)
            {
                const t_pos cur = q.front();
                q.pop();

                if (visited[cur.y][cur.x] == FLOWER)
                    continue ;

                for (int dir = 0; dir < dirSize; ++dir)
                {
                    t_pos next = {
                        cur.y + dy[dir],
                        cur.x + dx[dir]
                    };

                    if (!(0 <= next.y && next.y < ySize)
                        || !(0 <= next.x && next.x < xSize)
                        || map[next.y][next.x] == WATER)
                        continue ;

                    int &nextVisited = visited[next.y][next.x];
                    int visitedValue = getValue(move, type);
                    if (nextVisited == NOT_VISITED)
                    {
                        nextVisited = visitedValue;
                    }
                    else if (nextVisited == visitedValue * -1)
                    {
                        ++flowerCnt;
                        nextVisited = FLOWER;
                    }
                    else
                    {
                        continue ;
                    }

                    q.push(next);
                }
            }
        }
    }

    return (-1);
}

void    backTracking(int idx=0, int sowCnt=0)
{
    if (sowCnt == sowSum)
    {
        maxFlower = std::max(maxFlower, bfs());
        return ;
    }

    if (idx == sowable.size())
    {
        return ;
    }

    backTracking(idx + 1, sowCnt);
    for (int type = 0; type < CULTURE_TYPE; ++type)
    {
        int &cnt = cultureCnt[type];
        if (cnt == 0)
            continue ;

        t_vec<int> &land = landIdx[type];

        --cnt;
        land.push_back(idx);
        backTracking(idx + 1, sowCnt + 1);
        land.pop_back();
        ++cnt;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int type = 0; type < CULTURE_TYPE; ++type)
    {
        int &cnt = cultureCnt[type];

        std::cin >> cnt;
        sowSum += cnt;
    }
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            char &space = map[y][x];

            std::cin >> space;
            if (space == CULTURING)
            {
                sowable.push_back({y, x});
            }
        }
    }

    backTracking();
    std::cout << maxFlower << '\n';
    return (0);
}
