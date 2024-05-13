#include <iostream>
#include <queue>
#define RED_POS first
#define BLUE_POS second

enum e_space
{
    EMPTY = '.',
    WALL = '#',
    GOAL = 'O',
    RED = 'R',
    BLUE = 'B'
};

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX = 10;

int ySize, xSize;
char map[MAX][MAX + 1];
bool visited[MAX][MAX][MAX][MAX];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

inline int moveBead(t_pos &bead, int dir)
{
    int dist = 0;

    do
    {
        bead.y += dy[dir];
        bead.x += dx[dir];
        ++dist;
    } while (map[bead.y][bead.x] == EMPTY);

    if (map[bead.y][bead.x] != GOAL)
    {
        bead.y -= dy[dir];
        bead.x -= dx[dir];
    }
    return (dist);
}

int bfs(t_pos &startR, t_pos &startB)
{
    typedef std::pair<t_pos, t_pos> t_pair;

    int moveCnt = 1;
    std::queue<t_pair> q;

    visited[startR.y][startR.x][startB.y][startB.x] = true;
    q.push({startR, startB});
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            t_pair cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pair next = cur;
                t_pos &red = next.RED_POS;
                t_pos &blue = next.BLUE_POS;

                int redDist = moveBead(red, dir);
                int blueDist = moveBead(blue, dir);
                if (visited[red.y][red.x][blue.y][blue.x])
                    continue ;

                if (map[blue.y][blue.x] == GOAL)
                    continue ;

                if (map[red.y][red.x] == GOAL)
                    return (moveCnt);

                if (red == blue)
                {
                    if (redDist > blueDist)
                    {
                        red.y -= dy[dir];
                        red.x -= dx[dir];
                    }
                    else
                    {
                        blue.y -= dy[dir];
                        blue.x -= dx[dir];
                    }
                }

                if (visited[red.y][red.x][blue.y][blue.x])
                    continue ;

                visited[red.y][red.x][blue.y][blue.x] = true;
                q.push(next);
            }
        }
        ++moveCnt;
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos red = {-1, -1}, blue = {-1, -1};

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        if (red.y != -1 && blue.y != -1)
            continue ;

        for (int x = 0; x < xSize; ++x)
        {
            switch (map[y][x])
            {
            case RED:
                red = {y, x};
                map[red.y][red.x] = EMPTY;
                break;            
            case BLUE:
                blue = {y, x};
                map[blue.y][blue.x] = EMPTY;
                break;
            }
        }
    }

    std::cout << bfs(red, blue) << '\n';
    return (0);
}
