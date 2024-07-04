#include <iostream>
#include <queue>

enum e_space
{
    OCEAN = '0',
    LAND
};

struct t_pos
{
    int y, x;
    int dir;
};

struct t_edge
{
    int v;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int MAX_SIZE = 10;
const int MAX_ISLAND = 6;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int islandCnt;
int ySize, xSize;
bool visited[MAX_ISLAND];
char map[MAX_SIZE][MAX_SIZE];
int bridgeDist[MAX_ISLAND][MAX_ISLAND];
std::queue<t_pos> qs[MAX_ISLAND];

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

void    dfs(const t_pos &cur)
{
    qs[islandCnt].push(cur);
    map[cur.y][cur.x] = islandCnt;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            cur.y + dy[dir],
            cur.x + dx[dir]
        };

        if (!isBound(next) || map[next.y][next.x] != LAND)
            continue ;

        dfs(next);
    }
}

void    bfs(int id)
{
    std::queue<t_pos> &q = qs[id];

    int qSize = q.size();
    while (qSize--)
    {
        const t_pos cur = q.front();
        q.pop();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir],
                dir
            };

            if (!isBound(next) || map[next.y][next.x] != OCEAN)
                continue ;

            q.push(next);
        }
    }

    int curDist = 1;
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            t_pos next = q.front();
            q.pop();

            next.y += dy[next.dir];
            next.x += dx[next.dir];

            if (!isBound(next))
                continue ;

            const char &nextSpace = map[next.y][next.x];

            if (nextSpace < islandCnt)
            {
                if (curDist >= 2)
                {
                    int &nextDist = bridgeDist[id][nextSpace];

                    if (nextDist == 0 || nextDist > curDist)
                        nextDist = curDist;
                }
                continue ;
            }

            q.push(next);
        }
        ++curDist;
    }
}

int prim(int start=0)
{
    int madeEcnt = 0;
    int totalWeight = 0;
    std::priority_queue<t_edge> pq;

    pq.push({start, 0});
    while (!pq.empty()
            && madeEcnt != islandCnt)
    {
        const t_edge cur = pq.top();
        pq.pop();

        if (visited[cur.v])
            continue ;

        ++madeEcnt;
        totalWeight += cur.weight;
        visited[cur.v] = true;
        for (int nextV = 0; nextV < islandCnt; ++nextV)
        {
            int &nextWeight = bridgeDist[cur.v][nextV];
            if (nextWeight == 0)
                continue ;

            pq.push({nextV, nextWeight});
        }
    }

    return (madeEcnt == islandCnt ? totalWeight : -1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    for (t_pos pos = {0, 0}; pos.y < ySize; ++pos.y)
    {
        for (pos.x = 0; pos.x < xSize; ++pos.x)
        {
            const char &curSpace = map[pos.y][pos.x];

            if (curSpace != LAND)
                continue ;

            dfs(pos);
            ++islandCnt;
        }
    }

    for (int i = 0; i < islandCnt; ++i)
    {
        bfs(i);
    }

    std::cout << prim() << '\n';
    return (0);
}
