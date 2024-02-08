#include <iostream>
#include <vector>

enum e_space
{
    CLEANER = -1,
    EMPTY
};

struct t_pos
{
    int y, x;
};

const int MAX = 50;

int map[MAX][MAX];
int dust[MAX][MAX];
int ySize, xSize, time_;
int totalDust;
t_pos cleaner[2];

// 위 공기청정기는 +1
// 아래 공기청정기는 (+3) % 4
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void spreadDust()
{
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if (map[y][x] <= 0)
                continue ;
           
            int spreadedDust = map[y][x] / 5;
            for (int i = 0; i < 4; ++i)
            {
                t_pos next = {y + dy[i], x + dx[i]};
            
                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == CLEANER)
                    continue ;

                dust[next.y][next.x] += spreadedDust;
                dust[y][x] -= spreadedDust;
            }
        }
    }

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if (dust[y][x] == 0)
                continue ;

            map[y][x] += dust[y][x];
            dust[y][x] = 0;
        }
    }
}

inline bool shouldStop(t_pos &cur, t_pos &stop, int dirIdx, int i)
{
    switch (i) {
        case 0:
            switch (dirIdx) {
                case 0:
                    return cur.y == 0;
                case 1:
                    return cur.x == xSize - 1;
                case 2:
                    return cur.y == stop.y;
            }
            break ;
        case 1:
            switch (dirIdx) {
                case 2:
                    return cur.y == ySize - 1;
                case 1:
                    return cur.x == xSize - 1;
                case 0:
                    return cur.y == stop.y;
            }
    }
    if (cur.x == stop.x + 1)
    {
        map[stop.y][stop.x + 1] = 0;
        return (true);
    }
    return (false);
}

void workCleaners()
{
    static const int startDir[] = {0, 2};
    static const int plusDir[] = {1, 3};

    for (int i = 0; i < 2; ++i)
    {
        t_pos cur = cleaner[i];

        int dirCnt = 4;
        int dirIdx = startDir[i];

        cur.y += dy[dirIdx];
        cur.x += dx[dirIdx];

        totalDust -= map[cur.y][cur.x];
        while (dirCnt--)
        {
            do
            {
                map[cur.y][cur.x] = map[cur.y + dy[dirIdx]][cur.x + dx[dirIdx]];
                cur.y += dy[dirIdx];
                cur.x += dx[dirIdx];
            } while (!shouldStop(cur, cleaner[i], dirIdx, i));
            dirIdx += plusDir[i];
            dirIdx %= 4;
        }
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cleanerIdx = 0;

    std::cin >> ySize >> xSize >> time_;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
            if (map[y][x] > 0)
                totalDust += map[y][x];
            else if (map[y][x] == CLEANER)
                cleaner[cleanerIdx++] = {y, x};
        }
    }

    while (time_--)
    {
        spreadDust();
        workCleaners();
    }

    std::cout << totalDust << '\n';
    return 0;
}
