#include <iostream>
#include <deque>
#include <cstring>
#include <climits>

struct t_pos
{
    int y, x;
    int energy;
    
    inline bool operator==(const t_pos &other) const
    {
        return y == other.y && x == other.x;
    }
};

const int MAX_SIZE = 1000;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int minEnergy[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

int bfs(const t_pos &start, const t_pos &end)
{
    if (start == end)
        return 0;

    int endEnergy = INT_MAX;
    std::deque<t_pos> q;

    q.push_front(start);
    while (!q.empty())
    {
        const t_pos cur = q.front();
        q.pop_front();
        
        if (cur.energy >= endEnergy)
            continue;

        char &noEnergy = map[cur.y][cur.x];
        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir],
                cur.energy
            };
            
            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize))
                continue;
                
            int &nextEnergy = minEnergy[next.y][next.x];
            bool isNoEnergy = (dir == noEnergy);
            
            next.energy += !isNoEnergy;
            if (nextEnergy != 0 && nextEnergy <= next.energy)
                continue;

            if (next == end)
            {
                endEnergy = std::min(endEnergy, next.energy);
                continue;
            }
    
            nextEnergy = next.energy;
            if (isNoEnergy)
            {
                q.push_front(next);
            }
            else
            {
                q.push_back(next);
            }
        }
    }
    return endEnergy - 1;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    
    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        for (int x = 0; x < xSize; ++x)
        {
            map[y][x] -= '0';
        }
    }
    
    int testCnt;
    t_pos start, end;
    
    std::cin >> testCnt;
    while (testCnt--)
    {
        start.energy = 1;
        std::cin >> start.y >> start.x;
        std::cin >> end.y >> end.x;
        --start.y, --start.x;
        --end.y, --end.x;

        std::cout << bfs(start, end) << '\n';
        memset(minEnergy, false, sizeof(minEnergy));
    }
    return 0;
}
