#include <iostream>
#include <climits>
#include <deque>

enum e_space
{
    OCEAN = '.',
    WALL = '#',
    START = 'K',
    END = '*'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 500;
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);


int ySize, xSize;
int fuel[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

int bfs(const t_pos &start)
{
    int endFuel = INT_MAX;
    std::deque<t_pos> q;
    
    fuel[start.y][start.x] = 1;
    q.push_front(start);
    while (!q.empty())
    {
        const t_pos cur = q.front();
        const int &curFuel = fuel[cur.y][cur.x];
        q.pop_front();

        if (curFuel >= endFuel)
            continue;

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };
            
            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize)
                || map[next.y][next.x] == WALL)
                continue;

            bool takeFuel = (dir > 2); 
            int &cmpFuel = fuel[next.y][next.x];
            int nextFuel = curFuel + takeFuel;
            if (!(cmpFuel == 0 || cmpFuel > nextFuel))
                continue;

            cmpFuel = nextFuel;
            if (map[next.y][next.x] == END)
            {
                endFuel = std::min(endFuel, nextFuel);
                continue;
            }
            
            if (takeFuel)
                q.push_back(next);
            else
                q.push_front(next);
        }
    }
    return (endFuel == INT_MAX ? -1 : endFuel - 1);
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start = {-1, -1};

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        if (start.y != -1)
            continue;

        for (int x = 0; x < xSize; ++x)
        {
            if (map[y][x] == START)
            {
                start = {y, x};
                break;
            }
        }
    }

    std::cout << bfs(start) << '\n';
    return 0;
}
