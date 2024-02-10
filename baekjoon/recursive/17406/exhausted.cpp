#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>

const int MAX_SIZE = 50;
const int MAX_DEPTH = 6;

int map[MAX_SIZE][MAX_SIZE];
int ySize, xSize, cmdCnt;
int min = INT_MAX;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

struct t_rotate
{
    int centerY;
    int centerX;
    int gap;
    bool visited;

    inline static void rotateOneLine(
        int &curY, int &curX, int size, int dir)
    {
        while (--size)
        {
            map[curY][curX] = map[curY + dy[dir]][curX + dx[dir]];
            curY += dy[dir];
            curX += dx[dir];
        }
    }

    void rotate(int startDir, int step)
    {
        int startY = this->centerY - gap;
        int startX = this->centerX - gap;
        int saveDir = !startDir;

        int rectangeSize = gap * 2 + 1;
        while (rectangeSize != 1)
        {
            int dirCnt = 4;
            int dir = startDir;
            int moveY = startY, moveX = startX;
            int save = map[moveY][moveX];
            while (dirCnt--)
            {
                rotateOneLine(moveY, moveX, rectangeSize, dir);
                dir += step;
                dir %= 4;
            }
            map[startY + dy[saveDir]][startX + dx[saveDir]] = save;

            ++startY, ++startX;
            rectangeSize -= 2;
        }
    }
};

t_rotate cmds[MAX_DEPTH];

inline std::istream &operator>>(std::istream &in, t_rotate &input)
{
    in >> input.centerY >> input.centerX >> input.gap;
    --input.centerY;
    --input.centerX;
    input.visited = false;
    return (in);
}

void back_tracking(int depth)
{
    if (depth == cmdCnt)
    {
        for (int y = 0; y < ySize; ++y)
            min = std::min(
                min,
                std::accumulate(map[y], map[y] + xSize, 0)
            );
        return ;
    }

    for (int i = 0; i < cmdCnt; ++i)
    {
        t_rotate &cur = cmds[i];

        if (cur.visited)
            continue ;

        cur.visited = true;
        cur.rotate(1, 3);
        back_tracking(depth + 1);
        cur.rotate(0, 1);
        cur.visited = false;
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> cmdCnt;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
            std::cin >> map[y][x];
    }

    for (int i = 0; i < cmdCnt; ++i)
        std::cin >> cmds[i];

    back_tracking(0);

    std::cout << min << '\n';
    return 0;
}
