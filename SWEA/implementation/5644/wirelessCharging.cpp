#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

enum e_space
{
    EMPTY = 0
};

struct t_pos
{
    int y, x;

    inline bool operator!=(const t_pos &other) const
    {
        return (this->y != other.y || this->x != other.x);
    }
};

const int SIZE = 10;
const int MAX_BC = 8;
const int USER_CNT = 2;
const int MAX_MOVE = 100;
const int dy[] = {0, -1, 0, 1, 0};
const int dx[] = {0, 0, 1, 0, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int moveCnt;
int powers[MAX_BC + 1];
bool visited[SIZE][SIZE];
int map[SIZE][SIZE][USER_CNT];
int moveDirs[USER_CNT][MAX_MOVE];

void    setMap(int arr[2], int cIdx)
{
    int &curPower = powers[cIdx];
    int &bigPower = powers[arr[0]];
    int &smallPower = powers[arr[1]];

    if (bigPower < curPower)
    {
        arr[1] = arr[0];
        arr[0] = cIdx;
    }
    else if (smallPower < curPower)
    {
        arr[1] = cIdx;
    }
}

void    bfs(const t_pos &start, int dist, int cIdx)
{
    std::queue<t_pos> q;
    std::vector<t_pos> allPos;

    memset(visited, false, sizeof(visited));
    setMap(map[start.y][start.x], cIdx);
    visited[start.y][start.x] = true;
    q.push(start);
    while (dist--)
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
                    cur.x + dx[dir]
                };

                if (!(0 <= next.y && next.y < SIZE)
                    || !(0 <= next.x && next.x < SIZE)
                    || visited[next.y][next.x])
                    continue ;

                setMap(map[next.y][next.x], cIdx);
                visited[next.y][next.x] = true;
                q.push(next);
            }
        }
    }
}

inline void addPowers(int &totalPower, t_pos users[2])
{
    for (int u = 0; u < USER_CNT; ++u)
    {
        t_pos &curUser = users[u];
        int &toAdd = powers[map[curUser.y][curUser.x][0]];

        totalPower += toAdd;
    }
}

int    simulation(void)
{
    int totalPower = 0;
    t_pos users[] = {
        {0, 0},
        {SIZE - 1, SIZE - 1}
    };

    addPowers(totalPower, users);
    for (int m = 0; m < moveCnt; ++m)
    {
        for (int u = 0; u < USER_CNT; ++u)
        {
            int dir = moveDirs[u][m];
            t_pos &curUser = users[u];

            curUser.y += dy[dir];
            curUser.x += dx[dir];
        }

        int &oneBig = map[users[0].y][users[0].x][0];
        int &twoBig = map[users[1].y][users[1].x][0];
        if (oneBig != twoBig)
        {
            addPowers(totalPower, users);
        }
        else
        {
            int &oneSmall = map[users[0].y][users[0].x][1];
            int &twoSmall = map[users[1].y][users[1].x][1];
            int toAdd = std::max(
                powers[oneBig] + powers[twoSmall],
                powers[twoBig] + powers[oneSmall]
            );

            totalPower += toAdd;
        }
    }

    return (totalPower);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        int chargerCnt;

        std::cin >> moveCnt >> chargerCnt;
        for (int u = 0; u < USER_CNT; ++u)
        {
            for (int m = 0; m < moveCnt; ++m)
            {
                std::cin >> moveDirs[u][m];
            }
        }

        memset(map, 0, sizeof(map));
        for (int c = 1; c <= chargerCnt; ++c)
        {
            int y, x, dist;

            std::cin >> x >> y >> dist >> powers[c];
            bfs({y - 1, x - 1}, dist, c);
        }

        std::cout << '#' << t << ' ' << simulation() << '\n';
    }
    return (0);
}
