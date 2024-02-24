#include <iostream>
#include <vector>
#include <cstring>

struct t_cmd
{
    int dir;
    int dist;
};

struct t_pos
{
    int y, x;
};

const int MAX = 50;

int size;
int map[MAX][MAX];
bool wasHere[MAX][MAX];
std::vector<t_pos> clouds;

int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

inline std::istream &operator>>(std::istream &in, t_cmd &input)
{
    in >> input.dir >> input.dist;
    --input.dir;
    return (in);
}

int measureWater(void)
{
    int ret = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            ret += map[y][x];
        }
    }
    return (ret);
}

void    moveClouds(t_cmd &cmd)
{
    for (t_pos &cur : clouds)
    {
        for (int i = 0; i < cmd.dist; ++i)
        {
            cur.y += dy[cmd.dir];
            cur.x += dx[cmd.dir];

            if (cur.y == -1)
            {
                cur.y = size - 1;
            }
            else if (cur.y == size)
            {
                cur.y = 0;
            }

            if (cur.x == -1)
            {
                cur.x = size - 1;
            }
            else if (cur.x == size)
            {
                cur.x = 0;
            }
        }
    }
}

void    waterClouds(int delta)
{
    for (t_pos &cur : clouds)
    {
        map[cur.y][cur.x] += delta;
        wasHere[cur.y][cur.x] = true;
    }
}

void    magic(void)
{
    for (t_pos &cur : clouds)
    {
        int cnt = 0;
        int dirIdx = 1;
        
        for (int dirCnt = 4; dirCnt >= 1; --dirCnt, dirIdx += 2)
        {
            t_pos next = {cur.y + dy[dirIdx], cur.x + dx[dirIdx]};

            if (!(0 <= next.y && next.y < size)
                || !(0 <= next.x && next.x < size)
                || map[next.y][next.x] <= 0)
                continue ;

            ++cnt;
        }

        map[cur.y][cur.x] += cnt;
    }
}

void    makeClouds(void)
{
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            int &curSpace = map[y][x];

            if (curSpace >= 2 && !wasHere[y][x])
            {
                curSpace -= 2;
                clouds.push_back({y, x});
            }
        }
    }
}

void    printMap(void)
{
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            std::cout << map[y][x] << ' ';
        std::cout << '\n';
    }
    std::cout << "----------------------------" << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;

    std::cin >> size >> cmdCnt;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            std::cin >> map[y][x];
    }

    for (int y = 1; y <= 2; ++y)
    {
        for (int x = 0; x <= 1; ++x)
        {
            clouds.push_back({size - y, x});
        }
    }
    for (int i = 0; i < cmdCnt; ++i)
    {
        t_cmd cmd;
        std::cin >> cmd;

        moveClouds(cmd);
        waterClouds(1);
        magic();
        clouds.clear();
        makeClouds();
        memset(wasHere, false, sizeof(wasHere));
    }

    std::cout << measureWater() << '\n';
    return (0);
}
