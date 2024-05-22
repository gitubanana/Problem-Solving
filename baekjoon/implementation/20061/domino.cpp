#include <iostream>

int score;
static const int dy[] = {0, 0, 0, 1};
static const int dx[] = {0, 0, 1, 0};
static const int size[] = {0, 0, 1, 1};

struct t_green
{
    static const int X_SIZE = 4;
    static const int Y_SIZE = 6;

    bool map[Y_SIZE][X_SIZE];

    inline bool isPuttable(int putY, int putX, int type)
    {
        int i = 0;

        do
        {
            if (!(0 <= putY && putY < Y_SIZE)
                || !(0 <= putX && putX < X_SIZE))
                return (false);

            if (map[putY][putX])
                return (false);

            putY += dy[type];
            putX += dx[type];
            ++i;
        } while (i <= size[type]);
        return (true);
    }

    inline void makeBlockTrue(int putY, int putX, int type)
    {
        int i = 0;

        do
        {
            map[putY][putX] = true;
            putY += dy[type];
            putX += dx[type];
            ++i;
        } while (i <= size[type]);
    }

    void    pullRow(int y)
    {
        while (y >= 1)
        {
            int nextY = y - 1;

            for (int x = 0; x < X_SIZE; ++x)
            {
                map[y][x] = map[nextY][x];
            }
            y = nextY;
        }

        for (int x = 0; x < X_SIZE; ++x)
        {
            map[y][x] = false;
        }
    }

    void    putBlock(int putY, int putX, int type)
    {
        do
        {
            ++putY;
        } while (isPuttable(putY, putX, type));
        --putY;

        makeBlockTrue(putY, putX, type);

        for (int y = 2; y < Y_SIZE; ++y)
        {
            bool remove = true;

            for (int x = 0; x < X_SIZE; ++x)
            {
                if (!map[y][x])
                {
                    remove = false;
                    break ;
                }
            }

            if (remove)
            {
                pullRow(y);
                ++score, --y;
            }
        }

        int pullCnt = 0;
        for (int y = 0; y < 2; ++y)
        {
            for (int x = 0; x < X_SIZE; ++x)
            {
                if (map[y][x])
                {
                    ++pullCnt;
                    break ;
                }
            }
        }

        while (pullCnt--)
        {
            pullRow(Y_SIZE - 1);
        }
    }

    inline int countBlock(void)
    {
        int cnt = 0;

        for (int y = 0; y < Y_SIZE; ++y)
        {
            for (int x = 0; x < X_SIZE; ++x)
            {
                cnt += map[y][x];
            }
        }
        return (cnt);
    }
};

t_green green;
t_green blue;

inline int changeType(int type)
{
    static int change[] = {0, 1, 3, 2};
    return (change[type]);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;
    int y, x, type;

    std::cin >> cmdCnt;
    while (cmdCnt--)
    {
        std::cin >> type >> y >> x;
        green.putBlock(0, x, type);
        blue.putBlock(0, t_green::X_SIZE - y - 1 - (type == 3), changeType(type));
    }

    std::cout << score << '\n';
    std::cout << green.countBlock() + blue.countBlock() << '\n';
    return (0);
}
