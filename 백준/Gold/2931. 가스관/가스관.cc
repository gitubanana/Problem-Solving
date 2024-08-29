#include <iostream>
#include <unordered_map>
#include <vector>

enum e_space
{
    EMPTY = '.',
    START = 'M',
    END = 'Z'
};

enum e_dir
{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

struct t_pos
{
    int y, x;
    int dir;
};

template <typename K, typename V>
using t_umap = std::unordered_map<K, V>;

const int MAX_SIZE = 25;
const int FAIL = -1;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int totalBlock;
char map[MAX_SIZE][MAX_SIZE + 1];
t_umap<char, t_umap<int, int>> nextDirByBlock = {
    {'|', {{UP, UP}, {DOWN, DOWN}}},
    {'-', {{LEFT, LEFT}, {RIGHT, RIGHT}}},
    {'+', {{UP, UP}, {DOWN, DOWN}, {LEFT, LEFT}, {RIGHT, RIGHT}}},
    {'1', {{UP, RIGHT}, {LEFT, DOWN}}},
    {'2', {{DOWN, RIGHT}, {LEFT, UP}}},
    {'3', {{RIGHT, UP}, {DOWN, LEFT}}},
    {'4', {{RIGHT, DOWN}, {UP, LEFT}}}
};

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

int getNextDir(t_pos &cur)
{
    char &block = map[cur.y][cur.x];
    t_umap<int, int> &umap = nextDirByBlock[block];
    t_umap<int, int>::iterator it = umap.find(cur.dir);

    if (it == umap.end())
        return (FAIL);

    return (it->second);
}

void    beforeEmpty(t_pos &cur, int &cnt)
{
    do
    {
        ++cnt;
        cur.dir = getNextDir(cur);
        cur.y += dy[cur.dir];
        cur.x += dx[cur.dir];
    } while (map[cur.y][cur.x] != EMPTY);
}

bool toTheEnd(t_pos &cur, int &cnt)
{
    do
    {
        ++cnt;
        cur.dir = getNextDir(cur);
        if (cur.dir == FAIL)
        {
            return (false);
        }

        cur.y += dy[cur.dir];
        cur.x += dx[cur.dir];
    } while (map[cur.y][cur.x] != END);

    return (true);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos cur;

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];

        for (int x = 0; x < xSize; ++x)
        {
            switch (map[y][x])
            {
            case EMPTY: case END:
                break;
            case START:
                cur.y = y, cur.x = x;
                break;
            default:
                totalBlock += 1 + (map[y][x] == '+');
                break;
            }
        }
    }

    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            cur.y + dy[dir],
            cur.x + dx[dir],
            dir
        };

        if (inRange(next)
            && map[next.y][next.x] != EMPTY
            && map[next.y][next.x] != END)
        {
            cur = next;
            break ;
        }
    }

    int blockCnt = 0;

    beforeEmpty(cur, blockCnt);
    for (const char &block : "-|1234+")
    {
        map[cur.y][cur.x] = block;

        int nextDir = getNextDir(cur);
        if (nextDir == FAIL)
            continue ;

        t_pos next = {
            cur.y + dy[nextDir],
            cur.x + dx[nextDir],
            nextDir
        };

        if (!inRange(next)
            || map[next.y][next.x] == EMPTY)
            continue ;

        int cmpCnt = blockCnt;
        if (toTheEnd(next, cmpCnt) && cmpCnt == totalBlock + (block == '+'))
        {
            std::cout << cur.y + 1 << ' ' << cur.x + 1 << ' ' << block << '\n';
            break ;
        }
    }
    return (0);
}
