#include <iostream>
#include <deque>
#include <climits>

enum e_space
{
    WALL = '#',
    EMPTY = '.',
    START = 'S',
    END = 'E',
    ADJACENT = '!'
};

const int MAX_SIZE = 500;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int cameTime[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

inline bool adjacentToWall(const t_pos &pos)
{
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int checkY = pos.y + dy[dir];
        int checkX = pos.x + dx[dir];

        if (!(0 <= checkY && checkY < ySize)
            || !(0 <= checkX && checkX < xSize))
            continue ;

        if (map[checkY][checkX] == WALL)
        {
            return (true);
        }
    }
    return (false);
}

int bfs(const t_pos &start, const t_pos &end)
{
    int minTime = INT_MAX;
    std::deque<t_pos> q;

    cameTime[start.y][start.x] = 1;
    q.push_front(start);
    while (!q.empty())
    {
        const t_pos cur = q.front();
        int &curTime = cameTime[cur.y][cur.x];
        char &curSpace = map[cur.y][cur.x];
        q.pop_front();

        if (curTime >= minTime)
            continue ;

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir],
            };

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize)
                || map[next.y][next.x] == WALL)
                continue ;

            int &cmpTime = cameTime[next.y][next.x];
            char &nextSpace = map[next.y][next.x];
            bool takeNoTime = (curSpace == ADJACENT && nextSpace == ADJACENT);
            int nextTime = curTime + !takeNoTime;

            if (!(cmpTime == 0 || cmpTime > nextTime))
                continue ;

            cmpTime = nextTime;
            if (next == end)
            {
                minTime = std::min(minTime, nextTime);
                continue ;
            }

            if (nextSpace == ADJACENT)
            {
                q.push_front(next);
            }
            else
            {
                q.push_back(next);
            }
        }
    }
    return (minTime - 1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start = {-1, -1};
    t_pos end = {-1, -1};

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        if (start.y != -1 && end.y != -1)
            continue ;

        for (int x = 0; x < xSize; ++x)
        {
            switch (map[y][x])
            {
            case START:
                start.y = y, start.x = x;
                break;
            case END:
                end.y = y, end.x = x;            
                break;
            }
        }
    }

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            char &space = map[y][x];
            if (space == WALL)
                continue ;

            if (adjacentToWall({y, x}))
            {
                space = ADJACENT;
            }
        }
    }

    std::cout << bfs(start, end) << '\n';
    return (0);
}
