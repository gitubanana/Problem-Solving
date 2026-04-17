#include <iostream>
#include <climits>
#include <vector>
#include <map>

enum e_space
{
    EMPTY = 0
};

struct t_pos
{
    int y, x;
    int dir;
    int speed;
};

const int MAX_SIZE = 100;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, moldCnt;
int map[MAX_SIZE][MAX_SIZE];
std::map<int, t_pos, std::greater<int>> molds;

bool move(int size, t_pos &pos)
{
    int &oldSpace = map[pos.y][pos.x];
    if (pos.speed != 0 && oldSpace == size)
    {
        oldSpace = EMPTY;
    }

    pos.y += dy[pos.dir] * pos.speed;
    pos.x += dx[pos.dir] * pos.speed;
    for (int move = 0; move < 2; ++move)
    {
        if ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize))
            break ;

        if (pos.y >= ySize)
        {
            pos.y = 2 * (ySize - 1) - pos.y;
        }
        else if (pos.y < 0)
        {
            pos.y = -pos.y;
        }
        else if (pos.x >= xSize)
        {
            pos.x = 2 * (xSize - 1) - pos.x;
        }
        else if (pos.x < 0)
        {
            pos.x = -pos.x;
        }

        pos.dir ^= 1;
    }

    int &newSpace = map[pos.y][pos.x];
    if (newSpace > size)
    {
        return (false);
    }

    newSpace = size;
    return (true);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos p;
    int size;

    std::cin >> ySize >> xSize >> moldCnt;
    for (int i = 0; i < moldCnt; ++i)
    {
        std::cin >> p.y >> p.x >> p.speed >> p.dir >> size;
        --p.y, --p.x, --p.dir;

        p.speed %= 2 * ((p.dir <= 1 ? ySize : xSize) - 1);
        map[p.y][p.x] = size;
        molds.insert({size, p});
    }

    int ans = 0;
    for (int x = 0; x < xSize; ++x)
    {
        for (int y = 0; y < ySize; ++y)
        {
            int &curSpace = map[y][x];

            if (curSpace != EMPTY)
            {
                t_pos &bye = molds[curSpace];

                ans += curSpace;
                molds.erase(curSpace);
                curSpace = EMPTY;
                break ;
            }
        }

        // move Molds in descending order
        std::vector<int> toRemove;
        for (std::pair<const int, t_pos> &mold : molds)
        {
            if (!move(mold.first, mold.second))
            {
                toRemove.push_back(mold.first);
            }
        }

        for (const int &size : toRemove)
        {
            molds.erase(size);
        }
    }

    std::cout << ans << '\n';
    return 0;
}