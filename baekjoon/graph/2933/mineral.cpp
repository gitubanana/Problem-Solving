#include <iostream>
#include <vector>

enum e_space
{
    EMPTY = '.',
    MINERAL = 'x'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 100;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
std::vector<t_pos> cluster;

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

inline bool isMineral(const t_pos &pos)
{
    return (isBound(pos) && map[pos.y][pos.x] == MINERAL);
}

bool    hitMineral(t_pos &stick, int moveDir)
{
    while (isBound(stick))
    {
        char &stickSpace = map[stick.y][stick.x];
        if (stickSpace == MINERAL)
        {
            stickSpace = EMPTY;
            return (true);
        }

        stick.x += dx[moveDir];
    }

    return (false);
}

bool    dfs(const t_pos &cur)
{
    if (cur.y == ySize - 1)
        return (false);

    map[cur.y][cur.x] = EMPTY;
    cluster.push_back(cur);
    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            cur.y + dy[dir],
            cur.x + dx[dir]
        };

        if (!isMineral(next))
            continue ;

        if (!dfs(next))
            return (false);
    }

    return (true);
}

void    dropCluster()
{
    int plus = 0;
    bool dropEnds = false;

    while (!dropEnds)
    {
        ++plus;

        for (const t_pos &pos : cluster)
        {
            int nextY = pos.y + plus;

            if (!isBound({nextY, pos.x}) || map[nextY][pos.x] == MINERAL)
            {
                dropEnds = true;
                break ;
            }
        }
    }

    for (const t_pos &pos : cluster)
    {
        map[pos.y + plus - 1][pos.x] = MINERAL;
    }
}

void    simulation(t_pos stick, int moveDir)
{
    if (!hitMineral(stick, moveDir))
        return ;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            stick.y + dy[dir],
            stick.x + dx[dir]
        };

        if (!isMineral(next))
            continue ;

        cluster.clear();
        if (dfs(next))
        {
            dropCluster();
            break ;
        }

        for (const t_pos &pos : cluster)
        {
            map[pos.y][pos.x] = MINERAL;
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
    }

    int turnCnt;
    int xs[2] = {0, xSize - 1};

    std::cin >> turnCnt;
    for (int turn = 0; turn < turnCnt; ++turn)
    {
        int y;
        int moveDir = turn & 1;

        std::cin >> y;
        simulation({ySize - y, xs[moveDir]}, moveDir);
    }

    for (int y = 0; y < ySize; ++y)
    {
        std::cout << map[y] << '\n';
    }
    return (0);
}
