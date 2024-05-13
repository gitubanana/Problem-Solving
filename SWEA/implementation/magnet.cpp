#include <iostream>
#include <cstring>

struct t_wheel
{
    static const int SIZE = 8;

    enum e_idx
    {
        LEFT = 0,
        RIGHT = 1
    };

    int top;
    int idx[2];
    int magnet[SIZE];

    inline void init(void)
    {
        top = 0;
        idx[LEFT] = 6;
        idx[RIGHT] = 2;
    }

    inline void    rotateClockWise(void)
    {
        top = (top == 0 ? SIZE - 1 : top - 1);
        idx[LEFT] = (idx[LEFT] == 0 ? SIZE - 1 : idx[LEFT] - 1);
        idx[RIGHT] = (idx[RIGHT] == 0 ? SIZE - 1 : idx[RIGHT] - 1);
    }

    inline void    rotateCounterClockWise(void)
    {
        top = (top + 1) % SIZE;
        idx[LEFT] = (idx[LEFT] + 1) % SIZE;
        idx[RIGHT] = (idx[RIGHT] + 1) % SIZE;
    }
};

const int WHEEL_CNT = 4;

bool visited[WHEEL_CNT];
t_wheel wheels[WHEEL_CNT];

inline int getScore(void)
{
    int mul = 1;
    int score = 0;

    for (int i = 0; i < WHEEL_CNT; ++i)
    {
        t_wheel &cur = wheels[i];

        score += cur.magnet[cur.top] * mul;
        mul <<= 1;
    }
    return (score);
}

void    rotateAll(int moveIdx, int funcIdx)
{
    typedef void (t_wheel::*t_func)(void);
    static const int dx[] = {-1, 1};
    static const int dirSize = sizeof(dx) / sizeof(dx[0]);
    static const t_func rotateFuncs[] = {
        &t_wheel::rotateClockWise,
        &t_wheel::rotateCounterClockWise
    };

    t_wheel &cur = wheels[moveIdx];

    visited[moveIdx] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextIdx = moveIdx + dx[dir];

        if (!(0 <= nextIdx && nextIdx < WHEEL_CNT)
            || visited[nextIdx])
            continue ;

        t_wheel &next = wheels[nextIdx];

        if (cur.magnet[cur.idx[dir]] == next.magnet[next.idx[!dir]])
            continue ;

        rotateAll(nextIdx, !funcIdx);
    }

    (cur.*rotateFuncs[funcIdx])();
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;
    int testCnt;
    int moveIdx, cmd;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> cmdCnt;

        for (int y = 0; y < WHEEL_CNT; ++y)
        {
            wheels[y].init();
            for (int x = 0; x < t_wheel::SIZE; ++x)
            {
                std::cin >> wheels[y].magnet[x];
            }
        }

        while (cmdCnt--)
        {
            std::cin >> moveIdx >> cmd;
            --moveIdx;

            memset(visited, 0, sizeof(visited));
            rotateAll(moveIdx, (cmd == -1));
        }

        std::cout << "#" << t << ' ' << getScore() << '\n';
    }
    return (0);
}
