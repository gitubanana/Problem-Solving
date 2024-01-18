#include <iostream>
#include <queue>
#include <cstring>

enum e_space
{
    EMPTY = '0',
    WALL,
    TARGET = '#',
    ME = '*',
};

struct t_pos
{
    int y, x;
};

std::istream &operator>>(std::istream &in, t_pos &pos)
{
    in >> pos.y >> pos.x;
    --pos.y, --pos.x;
    return in;
}

const int MAX = 300;

char map[MAX][MAX + 1];
bool visited[MAX][MAX];
int ySize, xSize, time_ = 1;
t_pos start, target;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void simulation(void)
{
    std::queue<t_pos> q;

    while (true)
    {
        visited[start.y][start.x] = true;
        q.push(start);

        while (!q.empty())
        {
            t_pos &cur = q.front();

            for (int i = 0; i < 4; ++i)
            {
                t_pos next = {cur.y + dy[i], cur.x + dx[i]};

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize))
                    continue ;

                char &nextSpace = map[next.y][next.x];
                bool &nextVisited = visited[next.y][next.x];

                if (nextVisited)
                    continue ;

                switch (nextSpace)
                {
                case TARGET:
                    return ;
                case WALL:
                    nextVisited = true;
                    nextSpace = EMPTY;
                    break ;
                default:
                    nextVisited = true;
                    q.push(next);
                }
            }
            q.pop();
        }
        memset(visited, 0, sizeof(visited));
        ++time_;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    std::cin >> start >> target;
    for (int y = 0; y < ySize; ++y)
        std::cin >> map[y];

    simulation();

    std::cout << time_ << '\n';
    return (0);
}