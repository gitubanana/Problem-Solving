#include <iostream>
#include <vector>
#include <deque>

enum e_space
{
    START = 'S',
    END = 'E',
    WALL = '#',
    EMPTY = '.',
    VISITED = '!'
};

struct t_pos
{
    int z, y, x;
    int cnt;
};

const int dz[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

using t_map = std::vector<std::vector<std::string>>;

int bfs(t_map &map, t_pos &start)
{
    std::deque<t_pos> q;
    
    map[start.z][start.y][start.x] = VISITED;
    q.push_front(start);
    while (!q.empty())
    {
        t_pos cur = q.front();
        q.pop_front();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.z + dz[dir],
                cur.y + dy[dir],
                cur.x + dx[dir],
                cur.cnt
            };

            if (!(0 <= next.z && next.z < map.size())
                || !(0 <= next.y && next.y < map[0].size())
                || !(0 <= next.x && next.x < map[0][0].size())
                || map[next.z][next.y][next.x] == VISITED)
                continue;

            char &nextSpace = map[next.z][next.y][next.x];
            switch (nextSpace)
            {
                case EMPTY:
                    q.push_front(next);
                    break;
                case WALL:
                    ++next.cnt;
                    q.push_back(next);
                    break;
                case END:
                    return next.cnt;
            }
            nextSpace = VISITED;
        }
    }
    return -1;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio (0);
    
    int testCnt;
    int zSize, ySize, xSize;
    std::string row;
    
    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> zSize >> ySize  >> xSize;

        t_map map;
        t_pos start = {-1, -1, -1, -1};
        for (int z = 0; z < zSize; ++z)
        {
            std::vector<std::string> floor_;
            for (int y = 0; y < ySize; ++y)
            {
                std::cin >> row;
                floor_.push_back(row);
                
                if (start.z != -1)
                    continue;
    
                for (int x = 0; x < xSize; ++x)
                {
                    if (row[x] == START)
                    {
                        start = {z, y, x, 0};
                        break;
                    }
                }
            }
            map.push_back(floor_);
        }
        
        std::cout << bfs(map, start) << '\n';
    }

    return 0;
}
