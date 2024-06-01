#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

enum e_space
{
    WALL = 0
};

struct t_pos
{
    int y, x;
};

// 위 -> 1, 2, 5, 6
// 아래 -> 1, 2, 4, 7
// 왼쪽 -> 1, 3, 4, 5
// 오른쪽 -> 1, 3, 6, 7

const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
std::vector<int> moveDirs[] = {
    {},
    {0, 1, 2, 3},
    {0, 1},
    {2, 3},
    {0, 3},
    {1, 3},
    {1, 2},
    {0, 2}
};
std::vector<int> canGoSpaces[] = {
    {1, 2, 5, 6},
    {1, 2, 4, 7},
    {1, 3, 4, 5},
    {1, 3, 6, 7}
};

int ySize, xSize, moveTime;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

inline std::istream &operator>>(std::istream &in, t_pos &input)
{
    in >> input.y >> input.x;
    return (in);
}

inline bool canGo(const int &dir, const t_pos &next)
{
    std::vector<int> &check = canGoSpaces[dir];

    return ((0 <= next.y && next.y < ySize)
            && (0 <= next.x && next.x < xSize)
            && !visited[next.y][next.x]
            && std::find(check.begin(), check.end(), map[next.y][next.x])
                != check.end());
}

int bfs(const t_pos &start)
{
    int canGoCnt = 1;
    std::queue<t_pos> q;

    visited[start.y][start.x] = true;
    q.push(start);
    while (--moveTime
            && !q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            const int &curSpace = map[cur.y][cur.x];
            for (const int &dir : moveDirs[curSpace])
            {
                const t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (!canGo(dir, next))
                    continue ;

                visited[next.y][next.x] = true;
                ++canGoCnt;
                q.push(next);
            }
        }
    }

    return (canGoCnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    t_pos start;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> ySize >> xSize >> start >> moveTime;
        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                std::cin >> map[y][x];
            }
        }

        memset(visited, false, sizeof(visited));
        std::cout << "#" << t << ' ' << bfs(start) << '\n';
    }
    return (0);
}
