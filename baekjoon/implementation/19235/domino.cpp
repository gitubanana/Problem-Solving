#include <iostream>

int score;
static const int dy[] = {0, 0, 0, 1};
static const int dx[] = {0, 0, 1, 0};
static const int size[] = {0, 0, 1, 1};

struct t_green
{
    static const int X_SIZE = 4;
    static const int Y_SIZE = 6;

    int horizontalCnt;
    int map[Y_SIZE][X_SIZE];

    t_green(void) : horizontalCnt(1) { }

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

    inline void makeBlock(int putY, int putX, int type)
    {
        int i = 0;
        int idx = type;

        if (type == 2)
        {
            type = 2 * horizontalCnt++;
        }

        do
        {
            map[putY][putX] = type;
            putY += dy[idx];
            putX += dx[idx];
            ++i;
        } while (i <= size[idx]);
    } 
 
    inline bool isHorizontalBlock(int y, int x)
    {
        int nextX = x + 1;
        if (nextX >= X_SIZE)
            return (false);

        return (map[y][x] == map[y][nextX]);
    }

    inline void findNextDownY(int &downY, int x)
    {
        while (downY >= 0 && map[downY][x])
        {
            --downY;
        }
    }

    void    pullTillBlock(void)
    {
        static int downYs[X_SIZE];

        for (int x = 0; x < X_SIZE; ++x)
        {
            int &curDownY = downYs[x];

            curDownY = Y_SIZE - 1;
            findNextDownY(curDownY, x);
        }

        for (int y = Y_SIZE - 1; y >= 0; --y)
        {
            for (int x = 0; x < X_SIZE; ++x)
            {
                int &curDownY = downYs[x];

                if (curDownY <= y || map[y][x] == 0)
                    continue ;

                int &curSpace = map[y][x];
                if (curSpace & 1)
                {
                    map[curDownY--][x] = curSpace;
                    curSpace = 0;
                }
                else if (isHorizontalBlock(y, x))
                {
                    int otherX = x + 1;
                    int &otherDownY = downYs[otherX];
                    int putDownY = std::min(curDownY, otherDownY);

                    if (putDownY <= y
                       || map[putDownY][x] || map[putDownY][otherX])
                    {
                        curDownY = y - 1;
                        findNextDownY(curDownY, x);
                        continue ;
                    }

                    map[putDownY][x] = map[y][x];
                    map[y][x] = 0;

                    map[putDownY][otherX] = map[y][otherX];
                    map[y][otherX] = 0;

                    curDownY = putDownY - 1;
                    otherDownY = putDownY - 1;
                }
                else
                {
                    curDownY = y - 1;
                    findNextDownY(curDownY, x);
                }
            }
        }
    }

    inline bool removeRow()
    {
        bool removed = false;

        for (int y = 2; y < Y_SIZE; ++y)
        {
            int x = 0;
            for (; x < X_SIZE; ++x)
            {
                if (map[y][x] == 0)
                {
                    break ;
                }
            }

            if (x == X_SIZE)
            {
                for (int x = 0; x < X_SIZE; ++x)
                {
                    map[y][x] = 0;
                }
                removed = true;
                ++score;
            }
        }
        return (removed);
    }

    void    putBlock(int putY, int putX, int type)
    {
        do
        {
            ++putY;
        } while (isPuttable(putY, putX, type));
        --putY;

        makeBlock(putY, putX, type);
        while (removeRow())
        {
            pullTillBlock();
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

        for (int y = 0; y < pullCnt; ++y)
        {
            for (int x = 0; x < X_SIZE; ++x)
            {
                map[Y_SIZE - y - 1][x] = 0;
            }
        }
        if (pullCnt)
        {
            pullTillBlock();
        }
    }

    inline int countBlock(void)
    {
        int cnt = 0;

        for (int y = 0; y < Y_SIZE; ++y)
        {
            for (int x = 0; x < X_SIZE; ++x)
            {
                cnt += (map[y][x] != 0);
            }
        }
        return (cnt);
    }

    void    print(void)
    {
        std::cout << "================" << '\n';
        for (int y = 0; y < Y_SIZE; ++y)
        {
            for (int x = 0; x < X_SIZE; ++x)
            {
                std::cout << map[y][x];
            }
            std::cout << std::endl;
        }
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
