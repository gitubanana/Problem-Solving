#include <iostream>
#include <vector>
#include <tuple>

enum e_dir
{
    EAST = 0,
    NORTH,
    WEST,
    SOUTH
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 20;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE];
int plusScore[MAX_SIZE][MAX_SIZE];
std::vector<t_pos> sameNum;

inline bool isBound(int y, int x)
{
    return ((0 <= y && y < ySize)
            && (0 <= x && x < xSize));
}

struct t_dice
{
    static const int DICE_NUM = 7;

    char num[DICE_NUM];
    int y, x, dir;
    int up, front, right;

    t_dice(void)
        : y(0), x(0), dir(0), up(1), front(5), right(3)
    {
        for (int i = 1; i < DICE_NUM; ++i)
        {
            num[i] = i + '0';
        }
    }

    void move(void)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!isBound(nextY, nextX))
        {
            dir = (dir + 2) % dirSize;
            move();
            return ;
        }

        switch (dir)
        {
            case EAST:
                std::tie(up, front, right) = std::make_tuple(DICE_NUM - right, front, up);
                break ;
            case NORTH:
                std::tie(up, front, right) = std::make_tuple(front, DICE_NUM - up, right);
                break ;
            case WEST:
                std::tie(up, front, right) = std::make_tuple(right, front, DICE_NUM - up);
                break ;
            case SOUTH:
                std::tie(up, front, right) = std::make_tuple(DICE_NUM - front, up, right);
                break ;
        }

        y = nextY;
        x = nextX;

        char &bottomNum = num[DICE_NUM - up];
        char &mapNum = map[y][x];
        if (bottomNum > mapNum)
            dir = (dir + 3) % dirSize;
        else if (bottomNum < mapNum)
            dir = (dir + 1) % dirSize;
    }
};

void    dfs(int y, int x)
{
    char &curNum = map[y][x];

    plusScore[y][x] = -1;
    sameNum.push_back({y, x});
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!isBound(nextY, nextX)
            || map[nextY][nextX] != curNum
            || plusScore[nextY][nextX] != 0)
            continue ;

        dfs(nextY, nextX);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int moveCnt;

    std::cin >> ySize >> xSize >> moveCnt;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if (plusScore[y][x] != 0)
                continue ;

            char &curNum = map[y][x];

            sameNum.clear();
            dfs(y, x);

            int getScore = (curNum - '0') * sameNum.size();
            for (const t_pos &pos : sameNum)
            {
                plusScore[pos.y][pos.x] = getScore;
            }
        }
    }

    t_dice dice;
    int totalScore = 0;
    while (moveCnt--)
    {
        dice.move();
        totalScore += plusScore[dice.y][dice.x];
    }

    std::cout << totalScore << '\n';
    return (0);
}
