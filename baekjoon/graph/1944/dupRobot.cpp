#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

enum e_space
{
    EMPTY = '0',
    WALL = '1',
    START = 'S',
    KEY = 'K'
};

struct t_pos
{
    int y, x;
};

struct t_edge
{
    int from, to;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight < other.weight);
    }
};

const int MAX_SIZE = 50;
const int MAX_KEY_CNT = 251;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size, keyCnt;
int parents[MAX_KEY_CNT];
char map[MAX_SIZE][MAX_SIZE + 1];
std::vector<t_pos> nodes;
std::vector<t_edge> edges;
std::unordered_map<int, int> posToIdx;

int bfs(int start)
{
    static bool visited[MAX_KEY_CNT][MAX_KEY_CNT];

    int move = 1;
    int edgeCnt = 0;
    std::queue<t_pos> q;
    const t_pos &startPos = nodes[start];

    memset(visited, false, sizeof(visited));
    visited[startPos.y][startPos.x] = true;
    q.push(startPos);
    while (!q.empty())
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

                bool &nextVisited = visited[next.y][next.x];
                if (nextVisited)
                    continue ;

                char &nextSpace = map[next.y][next.x];
                switch (nextSpace)
                {
                case WALL:
                    continue;
                case EMPTY:
                    break;
                default:
                    ++edgeCnt;
                    int &to = posToIdx[next.y * size + next.x];
                    if (to > start)
                    {
                        edges.push_back({start, to, move});
                    }
                }

                nextVisited = true;
                q.push(next);
            }
        }

        ++move;
    }

    return (edgeCnt);
}

int getParent(int x)
{
    int &xParent = parents[x];
    if (xParent != x)
    {
        xParent = getParent(xParent);
    }
    return (xParent);
}

inline void    group(int y, int x)
{
    parents[getParent(y)] = getParent(x);
}

int prim(int start=0)
{
    int madeEcnt = 0;
    int totalWeight = 0;

    std::sort(edges.begin(), edges.end());
    for (const t_edge &edge : edges)
    {
        if (getParent(edge.from) != getParent(edge.to))
        {
            ++madeEcnt;
            totalWeight += edge.weight;
            if (madeEcnt == keyCnt)
                return (totalWeight);

            group(edge.from, edge.to);
        }
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> keyCnt;
    for (int y = 0; y < size; ++y)
    {
        std::cin >> map[y];

        for (int x = 0; x < size; ++x)
        {
            switch (map[y][x])
            {
            case START:
            case KEY:
                parents[nodes.size()] = nodes.size();
                posToIdx.insert({y * size + x, nodes.size()});
                nodes.push_back({y, x});
                break;
            }
        }
    }

    for (int from = 0; from < nodes.size(); ++from)
    {
        int edgeCnt = bfs(from);
        if (edgeCnt != keyCnt)
        {
            std::cout << "-1" << '\n';
            return (0);
        }
    }
    std::cout << prim() << '\n';
    return (0);
}
