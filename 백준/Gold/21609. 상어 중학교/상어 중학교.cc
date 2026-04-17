#include <iostream>
#include <cstring>
#include <vector>
#define CURMAP map[curIdx]
#define NEXTMAP map[nextIdx]

enum e_space
{
    EMPTY = -2,
    WALL,
    RED
};

struct t_pos
{
    int y, x;

    inline bool operator<(const t_pos &other) const
    {
        if (y != other.y)
            return (y < other.y);

        return (x < other.x);
    }
};

struct t_group
{
    std::vector<t_pos> colorPos;
    std::vector<t_pos> redPos;
    t_pos cmp;

    inline int getSize(void) const
    {
        return colorPos.size() + redPos.size();
    }

    inline bool operator<(const t_group &other) const
    {
        if (this->getSize() != other.getSize())
            return (this->getSize() < other.getSize());

        if (redPos.size() != other.redPos.size())
            return (redPos.size() < other.redPos.size());

        return (cmp < other.cmp);
    }
};

const int MAX_SIZE = 20;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size, score;
int curIdx, nextIdx;
int map[2][MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void    dfs(const t_pos &cur, int color, t_group &g)
{
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

        int &nextSpace = CURMAP[next.y][next.x];
        if (nextSpace == color)
        {
            g.colorPos.push_back(next);
        }
        else if (nextSpace == RED)
        {
            g.redPos.push_back(next);
        }
        else
        {
            continue ;
        }

        dfs(next, color, g);
    }
}

bool removeGroup(void)
{
    bool removed = false;
    t_group toRemove;

    memset(visited, false, sizeof(visited));
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            if (visited[y][x] || CURMAP[y][x] <= RED)
                continue ;

            t_group cmpGroup = {
                {{y, x}},
                {},
                {y, x}
            };

            dfs({y, x}, CURMAP[y][x], cmpGroup);
            if (cmpGroup.getSize() >= 2)
            {
                removed = true;
                toRemove = std::max(toRemove, cmpGroup);
            }

            for (const t_pos &pos : cmpGroup.redPos)
            {
                visited[pos.y][pos.x] = false;
            }
        }
    }

    // remove group!
    score += toRemove.getSize() * toRemove.getSize();
    for (const t_pos &pos : toRemove.colorPos)
    {
        CURMAP[pos.y][pos.x] = EMPTY;
    }
    for (const t_pos &pos : toRemove.redPos)
    {
        CURMAP[pos.y][pos.x] = EMPTY;
    }

    return (removed);
}

void    workGravity(void)
{
    for (int x = 0; x < size; ++x)
    {
        int downY = size - 1;
        while (downY >= 0 && CURMAP[downY][x] != EMPTY)
        {
            --downY;
        }

        for (int y = downY - 1; y >= 0; --y)
        {
            switch (CURMAP[y][x])
            {
                case EMPTY:
                    break ;
                case WALL:
                    downY = y - 1;
                    while (downY >= 0 && CURMAP[downY][x] != EMPTY)
                    {
                        --downY;
                    }
                    y = downY;
                    break ;
                default:
                    CURMAP[downY--][x] = CURMAP[y][x];
                    CURMAP[y][x] = EMPTY;
                    break ;
            }
        }
    }
}

void    turn_90degree(void)
{
    nextIdx = curIdx ^ 1;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            NEXTMAP[y][x] = CURMAP[x][size - y - 1];
        }
    }
    curIdx = nextIdx;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int typeCnt;

    std::cin >> size >> typeCnt;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> CURMAP[y][x];
        }
    }

    while (removeGroup())
    {
        workGravity();
        turn_90degree();
        workGravity();
    }

    std::cout << score << '\n';
    return 0;
}
