#include <iostream>

const int MAX = 101;
const int OPPOSITE = 2;
const int NEXT = 1;

bool map[MAX][MAX];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int dirs[1 << 10 + 1];

struct t_curve
{
    int startY, startX;
    int endY, endX;
    int lastDir;

    t_curve() : lastDir(0) {}

    void draw(void)
    {
        for (int i = lastDir; i >= 0; --i)
        {
            int nextDir = (dirs[i] + NEXT) % 4;

            dirs[++lastDir] = nextDir;
            endY += dy[nextDir];
            endX += dx[nextDir];
            if ((0 <= endY && endY < MAX)
                && (0 <= endX && endX < MAX))
                map[endY][endX] = true;
        }
    }
};

std::istream &operator>>(std::istream &in, t_curve &cur)
{
    in >> cur.startX >> cur.startY >> dirs[cur.lastDir];
    cur.endY = cur.startY + dy[dirs[cur.lastDir]];
    cur.endX = cur.startX + dx[dirs[cur.lastDir]];

    map[cur.startY][cur.startX] = true;
    map[cur.endY][cur.endX] = true;
    return (in);
}

int countSquare(void)
{
    int cnt = 0;

    for (int y = 0; y < MAX; ++y)
    {
        for (int x = 0; x < MAX; ++x)
        {
            if (map[y][x])
            {
                int checkY = y + 1;
                int checkX = x + 1;

                if (!(checkY < MAX && checkX < MAX))
                    continue ;

                cnt += (map[y][checkX] && map[checkY][x] && map[checkY][checkX]);
            }
        }
    }
    return (cnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int curveCnt;
    std::cin >> curveCnt;

    while (curveCnt--)
    {
        int generation;
        t_curve curve;

        std::cin >> curve >> generation;
        while (generation--)
            curve.draw();
    }

    std::cout << countSquare() << '\n';
    return (0);
}
