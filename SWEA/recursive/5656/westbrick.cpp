#include <iostream>
#include <climits>

enum e_space
{
    EMPTY = 0
};

const int Y_MAX = 15;
const int X_MAX = 12;

int ans;
int ySize, xSize, depthLimit;

struct t_map
{
    int map[Y_MAX][X_MAX];

    inline int countBrick(void)
    {
        int cnt = 0;

        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                cnt += (map[y][x] != EMPTY);
            }
        }
        return (cnt);
    }

    void    fallBricks(void)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int downY = ySize - 1;

            while (map[downY][x] != EMPTY)
            {
                --downY;
            }

            for (int y = downY - 1; y >= 0; --y)
            {
                if (map[y][x] == EMPTY)
                    continue ;

                map[downY--][x] = map[y][x];
                map[y][x] = EMPTY;
            }
        }
    }

    void    explode(int y, int x)
    {
        static const int dy[] = {-1, 1, 0, 0};
        static const int dx[] = {0, 0, -1, 1};
        static const int dirSize = sizeof(dy) / sizeof(dy[0]);

        int removeCnt = map[y][x] - 1;

        map[y][x] = EMPTY;
        if (removeCnt <= 0)
            return ;

        for (int dir = 0; dir < dirSize; ++dir)
        {
            int nextY = y;
            int nextX = x;

            for (int i = 0; i < removeCnt; ++i)
            {
                nextY += dy[dir];
                nextX += dx[dir];

                if (!(0 <= nextY && nextY < ySize)
                    || !(0 <= nextX && nextX < xSize))
                    break ;

                explode(nextY, nextX);
            }
        }
    }

    void    dropBead(int x)
    {
        int hitY = 0;

        while (hitY < ySize)
        {
            if (map[hitY][x] != EMPTY)
                break ;
            ++hitY;
        }

        if (hitY == ySize)
            return ;

        explode(hitY, x);
        fallBricks();
    }
};

void    back_tracking(t_map &board, int depth=0)
{
    if (depth == depthLimit)
    {
        ans = std::min(ans, board.countBrick());
        return ;
    }

    for (int x = 0; x < xSize; ++x)
    {
        t_map next = board;

        next.dropBead(x);
        back_tracking(next, depth + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    t_map board;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> depthLimit >> xSize >> ySize;
        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                std::cin >> board.map[y][x];
            }
        }

        ans = INT_MAX;
        back_tracking(board);
        std::cout << '#' << t << ' ' << ans << '\n';
    }
    return (0);
}
